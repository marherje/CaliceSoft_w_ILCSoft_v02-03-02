#!/bin/sh
# The next line is a comment in WISH but not at SHELL\
exec wish "$0" "$@"
#exec wish8.4 "$0" "$@" [for Scientific Linux: SL5]
#exec wish8.5 "$0" "$@" [for Scientific Linux: SL6]
#There is a link wish to wish8.4 and wish8.5 at DESY [SL5/SL6]
#
# Tool for monitoring and debug of the CondtitionsDB implementation.
# It uses the 'cdb-query' tool found in the tools directory
#
# Developed by Jorge Lima to the ATLAS-TDAQ FCUL-CERN collaboration
#  2002-08-16
#
# Added new feature to allow users to show thier own "/test_user" folder.
# By doing "export DBTestFld="/test_user"
#

package require Tix

# Set look and feel
tix resetoptions TixGray TK

# Global vars
set BINTOOL "/cvmfs/calice.desy.de/v04-15/x86_64_gcc49_sl6/build/myInstall/bin/cdbadmin"

set DBInitEnvVariableName DBInit
global EnvValue

set SHOWTESTFLD $env(DBTestFld)

# The call to the unix env vars
# Use catch command to catch any error
# Thanks to Riccardo Fabbri

if [ catch { set EnvValue $env($DBInitEnvVariableName) } CatchResult ] {
   puts "No $DBInitEnvVariableName environment variable set!\n"
   puts "Program Terminated\n"
   exit 1
} else {
   puts "==> Environment variable: $DBInitEnvVariableName"
   puts "==> Variable set to:   $EnvValue"
   puts "==> To be displayed DBTestFld=$SHOWTESTFLD"
}

set INITSTR $EnvValue

set FOLDERS ""
set FSETS ""
set TAGS ""
set TAGGED ""
set HUMANDAY ""
set HUMANTIME ""
set FIRST 0
set DRAWNTYPE ""
set DRAWNFOLDER ""
set DRAWNARG ""
set LOCKDATA 0

array set CANVAS {
    win ""
    width 1000
    height 200
    voffset 0
    hoffset 0
    vscale 1
    hscale 1
    grid 1
}

array set VIEW {
    folder ""
    object ""
    tag ""
}

# Selected items
set SEL_FOLDER "/"
set SEL_FSET ""
set SEL_ANYFLD ""
set SEL_TAG ""
set SEL_POINT 1104537600000000000
set IS_FSET 1

set maxtill 1609459199000000000

# Representation limits
array set LIMITS {
    lowertag 0
    uppertag 45
    since 1120305600000000000
    till 1151841600000000000
}

array set HELP {
    Manual {
NOT YET READY
    }
    About {
Conddbview V0.1
Conditions Database Viewer
Atlas Daq Lisbon collaboration
Jorge Lima
Jorge.Lima@fc.ul.pt
    }
}
#############################################################################
# Common dialog Head and Tail                                               #
#############################################################################

proc dialogHead { top title args } {
    catch {destroy $top}
    toplevel $top
    wm transient $top .
    wm title $top $title
    eval frame $top.main -relief flat $args
    return $top.main
}

proc dialogTailOkCancel { top okcmd cancelcmd } {
    frame $top.sep -borderwidth 2 -height 2 -relief sunken
    frame $top.buttons -relief flat
    button $top.buttons.ok -text Ok -width 10 -default active -command "$okcmd; destroy $top"
    button $top.buttons.cancel -text Cancel -width 10 -command "$cancelcmd; destroy $top"
    focus $top.buttons.ok
    pack $top.buttons.ok $top.buttons.cancel -padx 15 -pady 10 -side left -expand true
    pack $top.buttons -side bottom
    pack $top.sep -side bottom -fill x -padx 40
    pack $top.main -side top -padx 10 -pady 10 -expand true
    pack propagate $top.main 0
    wm resizable $top 0 0
    update
    grab set $top
    bind $top.buttons.ok <Return> { join [ list %top.buttons.ok invoke ]}
    tkwait window $top
    grab release $top
}

proc dialogTailClose { top {closecmd ""} } {
    frame $top.buttons -relief flat
    button $top.buttons.ok -text Close -width 10 -command "$closecmd; destroy $top"
    pack $top.buttons.ok -padx 30 -pady 10 -side right
    pack $top.buttons -side bottom -fill x
    pack $top.main -side top -padx 10 -pady 10 -fill both -expand true
    pack propagate $top.main 0
    update
}

#############################################################################
# Specific procedures                                                       #
#############################################################################

#
# Procedures to call 'cdb-query' tool
#
proc execute { command } {

    global  fd FIRST BINTOOL INITSTR env

    set options "-s$INITSTR"
    set retry 0
    while {$retry == 0} {
      set retry 1
      if { $FIRST == 0 } {
        set command [join [list $BINTOOL $options $command]]
#        puts $command
        if [catch { open "|$command" w+ } fd] {
	  ErrorDialog "Error while opening pipe" "Error while opening pipe"
        }
      } else {
#        puts $command
        if [catch { puts $fd $command } ] {
          set FIRST 0
          set retry 0
          ErrorDialog "binary crashed ... restarting" "binary crashed ... restarting"
        }
      }
      if [catch { flush $fd } ] {
          set FIRST 0
          set retry 0
  	  ErrorDialog "binary crashed ... restarting" "binary crashed ... restarting"
      }
    }
    while { ![eof $fd] } {
      set a [gets $fd]
#      puts $a
      if { $a == "end"} break
      eval $a
    }
    set FIRST 1

#    if [catch {close $fd} mess] {
#	ErrorDialog "Error returned by \"$BINTOOL\"" "\n$mess"
#	error "Error on \"execute\" while exec:\n $command"
#    }
}

#
# Procedures to delete folders
#

proc folderDelete { } {
  global SEL_FOLDER SEL_FSET FOLDERS
  set tmp_folder $SEL_FOLDER
  set frm [dialogHead .box1 "Folder Deletion" -width 500 -height 150]
  message $frm.msg -justify center -text "My Warning Message"
  tixOptionMenu $frm.o1 -label "Folder to delete: " -variable SEL_FOLDER \
      -options { label.width 15 label.anchor e menubutton.width 32}
  foreach fld $FOLDERS { $frm.o1 add command $fld -label $fld }
  if { $tmp_folder != "" } { set SEL_FOLDER $tmp_folder }
  pack $frm.o1 $frm.msg -side top -padx 10 -pady 10
  dialogTailOkCancel .box1 {deleteFolder} {}
}

#Note the function to be called is the same as when deleting
#folders do the fset delete works only if the fset is empty
proc fsetDelete { } {
  global SEL_FSET FSETS
  puts "Selected FSET is $SEL_FSET"
  set tmp_fset $SEL_FSET
  set frm [dialogHead .box1 "Folder Set Deletion" -width 500 -height 150]
  message $frm.msg -justify center -text "My Warning Message"
  tixOptionMenu $frm.o1 -label "Folder Set to delete: " -variable SEL_FSET \
      -options { label.width 15 label.anchor e menubutton.width 32 }
  foreach fld $FSETS { $frm.o1 add command $fld -label $fld }
  if { $tmp_fset != "" } { set SEL_FSET $tmp_fset }
  pack $frm.o1 $frm.msg -side top -padx 10 -pady 10
  dialogTailOkCancel .box1 {deleteFset} {}
}

proc deleteFolder {} {
global SEL_FOLDER
  puts  "Folder to delete is $SEL_FOLDER"
  execute "delete folder $SEL_FOLDER"
  readFolders
}

proc deleteFset {} {
global SEL_FSET
  puts  "Fset to delete is $SEL_FSET"
  execute "delete folder $SEL_FSET"
  readFolders
}


#############################################################################
# Routines for iterators                                                    #
#############################################################################

proc hIterObjs { } {
    global FOLDERS TAGS SEL_FOLDER SEL_TAG
    set tmp_folder $SEL_FOLDER
    set tmp_tag $SEL_TAG
    set frm [dialogHead .box1 "Horizontal iterator" -width 300 -height 200]
    tixOptionMenu $frm.o1 -label "Folder: " -variable SEL_FOLDER \
	    -options { label.width 9 label.anchor e menubutton.width 32 }
    foreach fld $FOLDERS { $frm.o1 add command $fld -label $fld }
    tixOptionMenu $frm.o2 -label "Tags: " -variable SEL_TAG \
	    -options { label.width 9 label.anchor e menubutton.width 15 }
    foreach tag $TAGS { $frm.o2 add command $tag -label $tag }
    tixLabelEntry $frm.e1 -label "Folder name: "
    [$frm.e1 subwidget entry] configure -textvariable SEL_FOLDER
    tixLabelEntry $frm.e2 -label "Tag name: "
    [$frm.e2 subwidget entry] configure -textvariable SEL_TAG
    pack $frm.o1 $frm.e1 $frm.o2 $frm.e2 -side top -padx 20 -pady 10
    if { $tmp_folder != "" } { set SEL_FOLDER $tmp_folder }
    if { $tmp_tag != "" } { set SEL_TAG $tmp_tag }
    dialogTailOkCancel .box1 {fillObjectView H $SEL_FOLDER $SEL_TAG} {}
}

proc vIterObjs { } {
    global FOLDERS TAGS SEL_FOLDER SEL_POINT
    global TMP_POINT_YEAR TMP_POINT_MONTH TMP_POINT_DAY TMP_POINT_HOUR TMP_POINT_MINUTE TMP_POINT_SECOND
    global HUMANDAY HUMANTIME HUMANCLOCK HUMANPICKY TSTAMP
    set tmp_folder $SEL_FOLDER
    set frm [dialogHead .box1 "Vertical iterator" -width 350 -height 150]
    tixOptionMenu $frm.o1 -label "Folder: " -variable SEL_FOLDER \
	    -options { label.width 9 label.anchor e menubutton.width 32 }
    foreach fld $FOLDERS { $frm.o1 add command $fld -label $fld }
    if { $tmp_folder != "" } { set SEL_FOLDER $tmp_folder }
    execute "converttime $SEL_POINT"
    set TMP_POINT_YEAR [string range $HUMANDAY 6 10]
    set TMP_POINT_MONTH [string range $HUMANDAY 3 5]
    set TMP_POINT_DAY [string range $HUMANDAY 0 2]
    set dotpos [string first . $HUMANTIME]
    set HUMANCLOCK [string range $HUMANTIME 0 [ expr $dotpos-1] ]
    set HUMANPICKY [string range $HUMANTIME $dotpos end]
    set TMP_POINT_HOUR [string range $HUMANCLOCK 0 1]
    set TMP_POINT_MINUTE [string range $HUMANCLOCK 3 4]
    set TMP_POINT_SECOND [string range $HUMANCLOCK 6 7]
    frame $frm.pointdate
    tixLabelEntry $frm.e11 -label "Point: "
    [$frm.e11 subwidget entry] configure -width 4 -textvariable TMP_POINT_YEAR
    tixLabelEntry $frm.e12 -label "/ "
    [$frm.e12 subwidget entry] configure -width 2 -textvariable TMP_POINT_MONTH
    tixLabelEntry $frm.e13 -label "/ "
    [$frm.e13 subwidget entry] configure -width 2 -textvariable TMP_POINT_DAY
    tixLabelEntry $frm.e14 -label "   "
    [$frm.e14 subwidget entry] configure -width 2 -textvariable TMP_POINT_HOUR
    tixLabelEntry $frm.e15 -label ": "
    [$frm.e15 subwidget entry] configure -width 2 -textvariable TMP_POINT_MINUTE
    tixLabelEntry $frm.e16 -label ": "
    [$frm.e16 subwidget entry] configure -width 2 -textvariable TMP_POINT_SECOND
    pack $frm.e11 $frm.e12 $frm.e13 $frm.e14 $frm.e15 $frm.e16 -in $frm.pointdate -side left -padx 5 -pady 10
    pack $frm.o1 $frm.pointdate -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
        execute "convertstamp $TMP_POINT_YEAR $TMP_POINT_MONTH $TMP_POINT_DAY $TMP_POINT_HOUR $TMP_POINT_MINUTE $TMP_POINT_SECOND"
	set $SEL_POINT $TSTAMP
        fillObjectView v $SEL_FOLDER $SEL_POINT
    } {}
}

proc aIterObjs { } {
    global FOLDERS TAGS SEL_FOLDER
    set tmp_folder $SEL_FOLDER
    set frm [dialogHead .box1 "Vertical iterator" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "Folder: " -variable SEL_FOLDER \
	    -options { label.width 9 label.anchor e menubutton.width 32 }
    foreach fld $FOLDERS { $frm.o1 add command $fld -label $fld }
    if { $tmp_folder != "" } { set SEL_FOLDER $tmp_folder }
    pack $frm.o1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {fillObjectView a $SEL_FOLDER ""} {}
}

proc quickaIterObjs { } {
    global SEL_FOLDER
    fillObjectView a $SEL_FOLDER ""
}

#############################################################################
# Folder procedures                                                         #
#############################################################################

proc folderCreate { } {
    global FSETS SEL_FSET tmp_folder tmp_parent
    set frm [dialogHead .box1 "Create folder" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "Parent folderSet: " -variable tmp_parent \
	    -options { label.anchor e menubutton.width 32 }
    foreach fset $FSETS { $frm.o1 add command $fset -label $fset }
    if { $SEL_FSET != "" } { set tmp_parent $SEL_FSET }
    tixLabelEntry $frm.e1 -label "New folder: "
    [$frm.e1 subwidget entry] configure -textvariable tmp_folder
    pack $frm.o1 $frm.e1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "create folder \"${tmp_parent}/${tmp_folder}\""
	readFolders
    } {}
}

proc folderTag { } {
    global TAGS SEL_TAG tmp_tag
    global FOLDERS SEL_FOLDER tmp_folder
    set frm [dialogHead .box1 "Tag folder" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "Folder to tag: " -variable tmp_folder \
	    -options { label.anchor e menubutton.width 32 }
    foreach fld $FOLDERS { $frm.o1 add command $fld -label $fld }
    if { $SEL_FOLDER != "" } { set tmp_folder $SEL_FOLDER }
    tixOptionMenu $frm.o2 -label "with tag: " -variable tmp_tag \
	    -options { label.anchor e menubutton.width 32 }
    foreach tag $TAGS { $frm.o2 add command $tag -label $tag }
    if { $SEL_TAG != "" } { set tmp_tag $SEL_TAG }
    pack $frm.o1 $frm.o2 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "tag folder \"$tmp_tag\" \"$tmp_folder\""
	readFolders
    } {}
}

proc folderSetTag { } {
    global TAGS SEL_TAG tmp_tag
    global FSETS SEL_FSET tmp_fset
    set frm [dialogHead .box1 "Tag folderSet" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "FolderSet to tag: " -variable tmp_fset \
	    -options { label.anchor e menubutton.width 32 }
    foreach fset $FSETS { $frm.o1 add command $fset -label $fset }
    if { $SEL_FSET != "" } { set tmp_fset $SEL_FSET }
    tixOptionMenu $frm.o2 -label "with tag: " -variable tmp_tag \
	    -options { label.anchor e menubutton.width 32 }
    foreach tag $TAGS { $frm.o2 add command $tag -label $tag }
    if { $SEL_TAG != "" } { set tmp_tag $SEL_TAG }
    pack $frm.o1 $frm.o2 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "tag folder \"$tmp_tag\" \"$tmp_fset\""
	readFolders
    } {}
}

proc folderSetCreate { } {
    global FSETS SEL_FSET tmp_parent tmp_fset
    set frm [dialogHead .box1 "Create folderSet" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "Parent folderSet: " -variable tmp_parent \
	    -options { label.anchor e menubutton.width 32 }
    foreach fset $FSETS { $frm.o1 add command $fset -label $fset }
    if { $SEL_FSET != "" } { set tmp_parent $SEL_FSET }
    tixLabelEntry $frm.e1 -label "New folderSet: "
    [$frm.e1 subwidget entry] configure -textvariable tmp_fset
    pack $frm.o1 $frm.e1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "create fset \"${tmp_parent}/${tmp_fset}\""
	readFolders
    } {}
}

#############################################################################
# Tag procedures                                                            #
#############################################################################

proc showTaggedFolders { tag } {
    global TAGGED
    set TAGGED ""
    execute "list tagged \"$tag\""
    set frm [dialogHead .tagged "Folders tagged with $tag" -width 400 -height 200]
    tixScrolledHList $frm.a -options {hlist.columns 3 hlist.header true}
    pack $frm.a -expand yes -fill both -side left
    set hlist [$frm.a subwidget hlist]
    $hlist header create 0 -itemtype text -text "Folder"
    $hlist header create 1 -itemtype text -text "Tag date"
 #   $hlist column width 2 0
    $hlist add .
    set i 0
    foreach {fld ins} $TAGGED {
	$hlist add .it$i -itemtype text -text $fld
	$hlist item create .it$i 1 -itemtype text -text $ins
	incr i
    }
    dialogTailClose .tagged {}
}

proc tagCreate { } {
    global tmp_tag tmp_desc
    set frm [dialogHead .box1 "Create tag" -width 300 -height 150]

    tixLabelEntry $frm.e1 -label "Tag name: "
    [$frm.e1 subwidget entry] configure -textvariable tmp_tag

    tixLabelEntry $frm.e2 -label "Description: "
    [$frm.e2 subwidget entry] configure -textvariable tmp_desc

    pack $frm.e1 $frm.e2 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "create tag \"$tmp_tag\" \"$tmp_desc\""
	readTags
    } {}
}

proc tagDelete { } {
    global TAGS SEL_TAG tmp_tag
    set frm [dialogHead .box1 "Delete tag" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "with tag: " -variable tmp_tag \
	    -options { label.anchor e menubutton.width 32 }
    foreach tag $TAGS { $frm.o1 add command $tag -label $tag }
    if { $SEL_TAG != "" } { set tmp_tag $SEL_TAG }
    pack $frm.o1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "tag delete \"$tmp_tag\""
	readTags
    } {}
}

proc tagRename { } {
    global TAGS SEL_TAG tmp_oldtag tmp_newtag
    set frm [dialogHead .box1 "Rename tag" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "with tag: " -variable tmp_oldtag \
	    -options { label.anchor e menubutton.width 32 }
    foreach tag $TAGS { $frm.o1 add command $tag -label $tag }
    if { $SEL_TAG != "" } { set tmp_oldtag $SEL_TAG }
    tixLabelEntry $frm.e1 -label "Tag name: "
    [$frm.e1 subwidget entry] configure -textvariable tmp_newtag
    pack $frm.o1 $frm.e1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	execute "tag rename \"$tmp_oldtag\" \"$tmp_newtag\""
	readTags
    } {}
}

proc tagListFolders { } {
    global TAGS SEL_TAG tmp_tag
    set frm [dialogHead .box1 "List tagged folders" -width 300 -height 150]
    tixOptionMenu $frm.o1 -label "with tag: " -variable tmp_tag \
	    -options { label.anchor e menubutton.width 32 }
    foreach tag $TAGS { $frm.o1 add command $tag -label $tag }
    if { $SEL_TAG != "" } { set tmp_tag $SEL_TAG }
    pack $frm.o1 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {showTaggedFolders $tmp_tag} {}
}

#############################################################################
# Object view                                                               #
#############################################################################

proc createObjectView { widget } {
    global CANVAS LIMITS
    set f [frame $widget.f]
    canvas $f.c -width 1100 -height 500 -bg white \
	    -xscrollcommand "$f.h set" -yscrollcommand "$f.v set"
    scrollbar $f.v -orient vertical -command "$f.c yview"
    scrollbar $f.h -orient horizontal -command "$f.c xview"
    grid $f.c -column 0 -row 0 -sticky nswe
    grid $f.v -column 1 -row 0 -sticky ns
    grid $f.h -column 0 -row 1 -sticky ew
    grid columnconfigure $f 0 -weight 1
    grid rowconfigure $f 0 -weight 1
    set CANVAS(win) $f.c

    return $f
}

proc fillObjectView { type folder {arg ""} } {
    global CANVAS LIMITS DRAWNFOLDER DRAWNTYPE DRAWNARG VIEW

    deleteObjects
    setvrange $LIMITS(lowertag) $LIMITS(uppertag)
    sethrange $LIMITS(since) $LIMITS(till)
    drawAxis $CANVAS(width) $CANVAS(height)

    set DRAWNFOLDER $folder
    set DRAWNTYPE $type
    set DRAWNARG $arg

    set oldcursor [$VIEW(object) cget -cursor]
    $VIEW(object).c configure -cursor watch
    switch $type {
	"a" {
	    execute "list objects $type \"$folder\""
	}
	"v" {
	    set point $arg
	    execute "list objects $type \"$folder\" \"$point\""
	}
	"H" {
	    set tag $arg
	    execute "list objects $type \"$folder\" $LIMITS(since) $LIMITS(till) \"$tag\""
	}
	default {error "BUG in fillObjectView caller"}
    }
    $VIEW(object).c xview moveto 0
    $VIEW(object).c yview moveto 0
    $VIEW(object).c configure -cursor $oldcursor
}

# Manipulate object view
proc deleteObjects {} {
    global CANVAS
    $CANVAS(win) delete all
}

proc drawAxis { width height } {
    global CANVAS LIMITS HUMANDAY HUMANTIME
    set margin 40
    set y1 [expr -$height-$margin]
    set y2 $margin
    set x1 -$margin
    set x2 [expr $width+$margin]
    set ax [expr $width+30]
    set ay [expr $height+5]
    for { set i 0 } { $i < [expr $LIMITS(uppertag)+1] } { incr i } {
	set y [expr -$i*$CANVAS(vscale)]
	$CANVAS(win) create line "-5 $y 0 $y"
	if { $CANVAS(grid) } {
	    $CANVAS(win) create line "0 $y $ax $y" -fill grey90
	}
    }
    set range [expr $LIMITS(till)-$LIMITS(since)]
    set t1 [expr $range/12]
    for { set i 0 } { $i < 13 } { incr i } {
	set x [expr round($i*$t1*$CANVAS(hscale))]
	set label [expr $LIMITS(since)+round($t1*$i)]
	$CANVAS(win) create line "$x 0 $x 5"
	if { $CANVAS(grid) } {
	    $CANVAS(win) create line "$x 0 $x -$ay" -fill lightblue
	    execute "converttime $label"
	    set dotpos [string first . $HUMANTIME]
	    set HUMANCLOCK [string range $HUMANTIME 0 [ expr $dotpos-1] ]
	    set HUMANPICKY [string range $HUMANTIME $dotpos end]
	    $CANVAS(win) create text "$x 20" -text $HUMANDAY -anchor n
	    $CANVAS(win) create text "$x 40" -text $HUMANCLOCK -anchor n
	    $CANVAS(win) create text "$x 60" -text $HUMANPICKY -anchor n
	}
    }
    $CANVAS(win) create line "-10 0 $ax 0" -arrow last
    $CANVAS(win) create line "0 10 0 -$ay" -arrow last
    $CANVAS(win) configure -scrollregion "$x1 $y1 $x2 $y2"
    set CANVAS(width) $width
    set CANVAS(height) $height
}

proc sethrange { since till } {
    global CANVAS
    set CANVAS(hscale) [expr $CANVAS(width)*1.0/($till-$since)]
    set CANVAS(hoffset) [expr -$CANVAS(hscale)*$since]
}

proc setvrange { lowerlayer upperlayer } {
    global CANVAS
    set CANVAS(vscale) 10
    set CANVAS(voffset) [expr $CANVAS(vscale)*$lowerlayer]
    set range [expr ($upperlayer-$lowerlayer)*$CANVAS(vscale)]
    if { $range > $CANVAS(height) } {
	set CANVAS(height) $range
    }
}

proc drawobject { since till layer color props description} {

    global CANVAS LASTDRAWCOMMAND
    set scale $CANVAS(hscale)
    set offset $CANVAS(hoffset)
    set x1 [expr $since*$scale+$offset]
    set x2 [expr $till*$scale+$offset]
    set scale $CANVAS(vscale)
    set offset $CANVAS(voffset)
    set y1 [expr -($layer+1)*$scale-$offset]
    set y2 [expr -$layer*$scale-$offset]
    set id [$CANVAS(win) create rectangle "$x1 $y1 $x2 $y2" -fill $color]
    $CANVAS(win) bind $id <Button-3> "openInfoPopup %W %x %y \"$props\""
    $CANVAS(win) bind $id <ButtonRelease-3> "closeInfoPopup %W"
    $CANVAS(win) bind $id <Button-1> "openWindow $layer $since $till \"$description\""
    # Button-2 doesn't work for me via remote NX
    # %X %Y is the pointer position
    $CANVAS(win) bind $id <Control-Button-3> "openSavePopup %W %X %Y \"$layer\" \"$since\" \"$till\""
    $CANVAS(win) bind $id <Control-ButtonRelease-3> "closeSavePopup %W"

}

proc openSavePopup { w x y layer since till } {

    catch { destroy $w.savePopup }

    menu $w.savePopup -tearoff 0
    # -command specifies a tcl proc
    $w.savePopup add command -label "Write SimpleFile (HEAD)" -command "popupWriteSimpleFile \"$layer\" \"$since\" \"$till\""
#    $w.savePopup add command -label "Write DBFile" -command "popupWriteDBFile \"$layer\" \"$since\" \"$till\""

    tk_popup $w.savePopup $x $y

}

proc closeSavePopup { w } {
    catch { destroy $w.savePopup }
}


proc popupWriteSimpleFile { layer since till } {

    global DRAWNFOLDER

    set tmp_folder $DRAWNFOLDER

    # executes passes its arguments to cdbadmin.cc (command == "something")
    execute "writeSimpleFile \"$tmp_folder\" \"$layer\" \"$since\" \"$till\" "

}

#proc popupWriteDBFile { layer since till } {
#
#    global DRAWNFOLDER
#    global SEL_TAG
#
#    set tmp_folder $DRAWNFOLDER
#    set tmp_tag $SEL_TAG
#
#    execute "writeDBFile \"$tmp_folder\" \"$tmp_tag\""
#
#}

proc openInfoPopup { w x y props } {
    catch { destroy $w.infoPopup }
    frame $w.infoPopup -bg black -borderwidth 1
    set n 1
    foreach {label val} $props {
	label $w.infoPopup.l$n -text $label -bg yellow -anchor e
	label $w.infoPopup.v$n -text $val -bg white -anchor w
	grid $w.infoPopup.l$n -row $n -column 0 -sticky nsew
	grid $w.infoPopup.v$n -row $n -column 1 -sticky nsew
	incr n
    }
    place $w.infoPopup -x $x -y $y
}

proc closeInfoPopup { w } {
    catch { destroy $w.infoPopup }
}

proc openWindow { layer since till props}  {

    global DRAWNFOLDER LOCKDATA

    if { $LOCKDATA==1 } { return }
    set LOCKDATA 1
    set frm [dialogHead .box2 "Open Database" -width 600 -height 800]
    set t [text .box2.t -setgrid true -wrap word -width 20 -height 450 -yscrollcommand ".box2.scry set"]
    scrollbar .box2.scry -orient vert -command ".box2.t yview"
    pack .box2.scry -side right -fill y
    pack .box2.t -side left -fill both -expand true
    wm maxsize .box2 300 70
    wm minsize .box2 100 70
    set oldcursor [$t cget -cursor]
    $t configure -cursor watch
    $t insert end ["databases" $layer $since $till $DRAWNFOLDER $props]
    $t configure -cursor $oldcursor
    set LOCKDATA 0
}

proc databases  { layer since till folder props} {

    global FIRST INITSTR BINTOOL fd env

    set text ""
    set command [join [list "datas" $layer $since $till "\"$folder\"" \"$props\"]]
    set options "-s$INITSTR"
    set retry 0
    while {$retry == 0} {
      set retry 1
      if { $FIRST == 0 } {
        set command [join [list $BINTOOL $options $command]]
        if [catch { open "|$command" w+ } fd] {
	  ErrorDialog "Error while opening pipe" "Error while opening pipe"
        }
      } else {
#        puts $command
        if [catch { puts $fd $command } ] {
          set FIRST 0
          set retry 0
          ErrorDialog "binary crashed ... restarting" "binary crashed ... restarting"
        }
      }
      if [catch { flush $fd } ] {
          set FIRST 0
          set retry 0
  	  ErrorDialog "binary crashed ... restarting" "binary crashed ... restarting"
      }
    }
    while { ![eof $fd] } {
      set a [gets $fd ]
      if {$a =="end"} {break}
      append text $a
      append text "\n"
    }
    return $text
}

proc print {text} {
    return $text
}


proc SetupView {} {
    global CANVAS LIMITS TMP_SINCE TMP_TILL DRAWNTYPE DRAWNFOLDER DRAWNARG
    set TMP_SINCE $LIMITS(since)
    set TMP_TILL $LIMITS(till)
    set frm [dialogHead .box1 "Visualization limits" -width 300 -height 150]
    tixLabelEntry $frm.e1 -label "Since: "
    [$frm.e1 subwidget entry] configure -textvariable TMP_SINCE
    tixLabelEntry $frm.e2 -label "Till: "
    [$frm.e2 subwidget entry] configure -textvariable TMP_TILL
    pack $frm.e1 $frm.e2 -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
	set LIMITS(since) $TMP_SINCE
	set LIMITS(till) $TMP_TILL
	if { $DRAWNTYPE != ""} {
          fillObjectView $DRAWNTYPE $DRAWNFOLDER $DRAWNARG
	}
    } {}
}

proc SetupView {} {
    global CANVAS LIMITS TMP_SINCE TMP_TILL DRAWNTYPE DRAWNFOLDER DRAWNARG
    global TMP_SINCE_YEAR TMP_SINCE_MONTH TMP_SINCE_DAY TMP_TILL_YEAR TMP_TILL_MONTH TMP_TILL_DAY
    global TMP_SINCE_HOUR TMP_SINCE_MINUTE TMP_SINCE_SECOND TMP_TILL_HOUR TMP_TILL_MINUTE TMP_TILL_SECOND
    global HUMANDAY HUMANTIME HUMANCLOCK HUMANPICKY TSTAMP
    set TMP_SINCE $LIMITS(since)
    set TMP_TILL $LIMITS(till)
    execute "converttime $TMP_SINCE"
    set TMP_SINCE_YEAR [string range $HUMANDAY 6 10]
    set TMP_SINCE_MONTH [string range $HUMANDAY 3 5]
    set TMP_SINCE_DAY [string range $HUMANDAY 0 2]
    set dotpos [string first . $HUMANTIME]
    set HUMANCLOCK [string range $HUMANTIME 0 [ expr $dotpos-1] ]
    set HUMANPICKY [string range $HUMANTIME $dotpos end]
    set TMP_SINCE_HOUR [string range $HUMANCLOCK 0 1]
    set TMP_SINCE_MINUTE [string range $HUMANCLOCK 3 4]
    set TMP_SINCE_SECOND [string range $HUMANCLOCK 6 7]
    execute "converttime $TMP_TILL"
    set TMP_TILL_YEAR [string range $HUMANDAY 6 10]
    set TMP_TILL_MONTH [string range $HUMANDAY 3 5]
    set TMP_TILL_DAY [string range $HUMANDAY 0 2]
    set dotpos [string first . $HUMANTIME]
    set HUMANCLOCK [string range $HUMANTIME 0 [ expr $dotpos-1] ]
    set HUMANPICKY [string range $HUMANTIME $dotpos end]
    set TMP_TILL_HOUR [string range $HUMANCLOCK 0 1 ]
    set TMP_TILL_MINUTE [string range $HUMANCLOCK 3 4 ]
    set TMP_TILL_SECOND [string range $HUMANCLOCK 6 7 ]
    set frm [dialogHead .box1 "Visualization limits" -width 350 -height 150]
    frame $frm.sincedate
    tixLabelEntry $frm.e11 -label "Since: "
    [$frm.e11 subwidget entry] configure -width 4 -textvariable TMP_SINCE_YEAR
    tixLabelEntry $frm.e12 -label "/ "
    [$frm.e12 subwidget entry] configure -width 2 -textvariable TMP_SINCE_MONTH
    tixLabelEntry $frm.e13 -label "/ "
    [$frm.e13 subwidget entry] configure -width 2 -textvariable TMP_SINCE_DAY
    tixLabelEntry $frm.e14 -label "   "
    [$frm.e14 subwidget entry] configure -width 2 -textvariable TMP_SINCE_HOUR
    tixLabelEntry $frm.e15 -label ": "
    [$frm.e15 subwidget entry] configure -width 2 -textvariable TMP_SINCE_MINUTE
    tixLabelEntry $frm.e16 -label ": "
    [$frm.e16 subwidget entry] configure -width 2 -textvariable TMP_SINCE_SECOND
    pack $frm.e11 $frm.e12 $frm.e13 $frm.e14 $frm.e15 $frm.e16 -in $frm.sincedate -side left -padx 5 -pady 10
    frame $frm.tilldate
    tixLabelEntry $frm.e21 -label "Till:  "
    [$frm.e21 subwidget entry] configure -width 4 -textvariable TMP_TILL_YEAR
    tixLabelEntry $frm.e22 -label "/ "
    [$frm.e22 subwidget entry] configure -width 2 -textvariable TMP_TILL_MONTH
    tixLabelEntry $frm.e23 -label "/ "
    [$frm.e23 subwidget entry] configure -width 2 -textvariable TMP_TILL_DAY
    tixLabelEntry $frm.e24 -label "   "
    [$frm.e24 subwidget entry] configure -width 2 -textvariable TMP_TILL_HOUR
    tixLabelEntry $frm.e25 -label ": "
    [$frm.e25 subwidget entry] configure -width 2 -textvariable TMP_TILL_MINUTE
    tixLabelEntry $frm.e26 -label ": "
    [$frm.e26 subwidget entry] configure -width 2 -textvariable TMP_TILL_SECOND
    pack $frm.e21 $frm.e22 $frm.e23 $frm.e24 $frm.e25 $frm.e26 -in $frm.tilldate -side left -padx 5 -pady 10
    pack $frm.sincedate $frm.tilldate -side top -padx 20 -pady 10
    dialogTailOkCancel .box1 {
        execute "convertstamp $TMP_SINCE_YEAR $TMP_SINCE_MONTH $TMP_SINCE_DAY $TMP_SINCE_HOUR $TMP_SINCE_MINUTE $TMP_SINCE_SECOND"
	set LIMITS(since) $TSTAMP
        execute "convertstamp $TMP_TILL_YEAR $TMP_TILL_MONTH $TMP_TILL_DAY $TMP_TILL_HOUR $TMP_TILL_MINUTE $TMP_TILL_SECOND"
        set LIMITS(till) $TSTAMP
	if { $DRAWNTYPE != ""} {
          fillObjectView $DRAWNTYPE $DRAWNFOLDER $DRAWNARG
	}
    } {}
}

proc zoomIn {} {
  global LIMITS DRAWNTYPE DRAWNFOLDER DRAWNARG
  set oldsince $LIMITS(since)
  set oldtill $LIMITS(till)
  set step [expr ($oldtill-$oldsince)/4]
  set LIMITS(since) [ expr $oldsince+$step ]
  set LIMITS(till) [ expr $oldtill-$step ]
  if { $DRAWNTYPE != ""} {
    if { $DRAWNARG == ""} {
      set DRAWNARG "HEAD"
    }
    fillObjectView H $DRAWNFOLDER $DRAWNARG
  }
}

proc zoomOut {} {
  global LIMITS DRAWNTYPE DRAWNFOLDER DRAWNARG
  set oldsince $LIMITS(since)
  set oldtill $LIMITS(till)
  set step [expr ($oldtill-$oldsince)/2]
  set LIMITS(since) [ expr $oldsince-$step ]
  set LIMITS(till) [ expr $oldtill+$step ]
  if { $DRAWNTYPE != ""} {
    if { $DRAWNARG == ""} {
      set DRAWNARG "HEAD"
    }
    fillObjectView H $DRAWNFOLDER $DRAWNARG
  }
}

proc moveLeft {} {
  global LIMITS DRAWNTYPE DRAWNFOLDER DRAWNARG
  set step [expr ($LIMITS(till)-$LIMITS(since))/2]
  if { $LIMITS(since)-$step>0 } {
    set LIMITS(since) [expr $LIMITS(since)-$step]
    set LIMITS(till) [expr $LIMITS(till)-$step]
  } else {
    set LIMITS(since) 0
    set LIMITS(till) [expr 2*$step]
  }
  if { $DRAWNTYPE != ""} {
    if { $DRAWNARG == ""} {
      set DRAWNARG "HEAD"
    }
    fillObjectView H $DRAWNFOLDER $DRAWNARG
  }
}

proc moveRight {} {
  global LIMITS DRAWNTYPE DRAWNFOLDER DRAWNARG maxtill
  set step [expr ($LIMITS(till)-$LIMITS(since))/2]
  if { $LIMITS(till)+$step<=$maxtill } {
    set LIMITS(since) [expr $LIMITS(since)+$step]
    set LIMITS(till) [expr $LIMITS(till)+$step]
  } else {
    set LIMITS(since) [expr $maxtill-2*$step]
    set LIMITS(till) $maxtill
  }
  if { $DRAWNTYPE != ""} {
    if { $DRAWNARG == ""} {
      set DRAWNARG "HEAD"
    }
    fillObjectView H $DRAWNFOLDER $DRAWNARG
  }
}

proc showAll {} {
  global DRAWNTYPE DRAWNFOLDER DRAWNARG
  if { $DRAWNTYPE != ""} {
    fillObjectView a $DRAWNFOLDER $DRAWNARG
  }
}

#############################################################################
# Folder view                                                               #
#############################################################################

proc createFolderView { widget } {
    proc openFolderPopup { x y } {
	global IS_FSET
	if { $IS_FSET } {
	    tk_popup .folderSetPopup $x $y
	} else {
	    tk_popup .folderPopup $x $y
	}
    }
    menu .folderSetPopup -tearoff 0
    .folderSetPopup add command -label "Tag folderSet" -command folderSetTag
    .folderSetPopup add command -label "Add folder" -command folderCreate
    .folderSetPopup add command -label "Add folderSet" -command folderSetCreate
    .folderSetPopup add command -label "Delete folderSet" -command fsetDelete
    menu .folderPopup -tearoff 0
    .folderPopup add command -label "Tag folder" -command folderTag
    .folderPopup add command -label "Delete folder" -command folderDelete
    .folderPopup add command -label "Display folder for tag" -command hIterObjs
    .folderPopup add command -label "Display folder for time" -command vIterObjs
    .folderPopup add command -label "Display folder" -command quickaIterObjs
    tixTree $widget.v -options { separator "/" } -browsecmd selectDir
    bind [$widget.v subwidget hlist] <Button-3> {openFolderPopup %X %Y}
    return $widget.v
}

proc fillFolderView { treeWidget } {
    global FSETS FOLDERS SHOWTESTFLD
    set hlist [$treeWidget subwidget hlist]
    $hlist delete all
    set TESTFLENTH [string length $SHOWTESTFLD]
    foreach d [lsort $FSETS] {
	set CHECKRANGE [string range $d 0 $TESTFLENTH]
	if {  $TESTFLENTH > 4
	      && [string match  *$SHOWTESTFLD* $CHECKRANGE] } {
	    #puts "Show test folder $d"
	} elseif { [string match -nocase *TEST* $d]} {
	    continue
	} else {
	    #no op!
	}
	set text [lindex [split $d /] end]
	$hlist add $d -itemtype imagetext -text $text -image [tix getimage folder]
        set myFirst [string first "/" $d ]
        set myLast [string last "/" $d ]
        if { $myFirst != $myLast } {
            $hlist hide entry $d
        }
    }
    foreach d $FOLDERS {
	set CHECKRANGE [string range $d 0 $TESTFLENTH]
	if { $TESTFLENTH > 4
	     && [string match   *$SHOWTESTFLD* $CHECKRANGE] } {
	    #puts "Show test folder $d"
	} elseif { [string match -nocase *TEST* $d]} {
	    continue
	} else {
	    #no op!
	}
	set text [lindex [split $d /] end]
#	puts $text
	$hlist add $d -itemtype imagetext -text $text -image [tix getimage file]
        $hlist hide entry $d
    }
    $treeWidget autosetmode
}

proc selectDir { entry } {
    global SEL_FOLDER SEL_FSET SEL_ANYFLD
    global FOLDERS FSETS IS_FSET
    set SEL_ANYFLD $entry
    if { [lsearch $FOLDERS $entry]>=0 } {
	set SEL_FOLDER $entry
	set IS_FSET 0
    } else {
	set SEL_FSET $entry
	set IS_FSET 1
    }
}

proc readFolders {} {
    global VIEW FOLDERS FSETS
    set FSETS ""
    set FOLDERS ""
    execute "list fsets"
    execute "list folders"
    fillFolderView $VIEW(folder)
}


proc createSpeedButtons { widget } {
    button .past -text past -command "moveLeft"
    button .zoomin -text "ZOOM" -command "zoomIn"
    button .zoomout -text "zoom" -command "zoomOut"
    button .future -text future -command "moveRight"
    frame $widget.f
    pack .past .zoomin .zoomout .future -fill x -in $widget.f -side left -anchor s -expand yes
    return $widget.f
}

proc createShowAllButton { widget } {
    button .showall -text "show all layers" -command "showAll"
    frame $widget.f2
    pack .showall -fill x -in $widget.f2 -side left -anchor s -expand yes
    return $widget.f2
}

#############################################################################
# Tag view                                                                  #
#############################################################################

proc createTagView { widget } {
    menu .tagPopup -tearoff 0
    .tagPopup add command -label "Create tag" -command tagCreate
    .tagPopup add command -label "Delete tag" -command tagDelete
    .tagPopup add command -label "Rename tag" -command tagRename
    .tagPopup add separator
    .tagPopup add command -label "List tagged folders" -command tagListFolders
    tixTree $widget.v -browsecmd selectTag
    bind [$widget.v subwidget hlist] <Button-3> {tk_popup .tagPopup %X %Y}
    return $widget.v
}

proc fillTagView { tagWidget } {
    global TAGS
    set hlist [$tagWidget subwidget hlist]
    $hlist delete all
    foreach t $TAGS {
	$hlist add $t -text $t
    }
}

proc selectTag { entry } {
    global SEL_TAG
    set SEL_TAG $entry
}

proc readTags {} {
    global VIEW TAGS
    set TAGS ""
    execute "list tags"
    fillTagView $VIEW(tag)
}

#############################################################################
# Callbacks                                                                 #
#############################################################################

proc object { layer since since1 since2 till till1 till2 descr } {
    global CANVAS LIMITS
    set SINCE $LIMITS(since)
    set TILL $LIMITS(till)
    set props [list Since: "$since1 $since2" Till: "$till1 $till2" Layer: $layer Description: $descr]
    regsub -all " " $descr "_" newdescr
    if { $since>$TILL || $till<$SINCE } return
    if { $till>$TILL || $till=="+Inf" } { set till $TILL }
    if { $since<$SINCE || $since=="-Inf" } { set since $SINCE }
    if { $descr=="Empty object" } {
	drawobject $since $till $layer grey90 $props $newdescr
    } else {
	drawobject $since $till $layer grey60 $props $newdescr
    }
}

proc folder { foldername } {
    global FOLDERS
    lappend FOLDERS $foldername
}

proc folderset { foldername } {
    global FSETS
    lappend FSETS $foldername
}

proc delete { foldername } {
    global FSETS
    lappend FSETS $foldername
}

proc tag { tagname } {
    global TAGS
    lappend TAGS $tagname
}

proc tagged { folder instime } {
    global TAGGED
    lappend TAGGED $folder $instime
}

proc human { hday htime } {
    global HUMANDAY HUMANTIME
    set HUMANDAY $hday
    set HUMANTIME $htime
}

proc timestamp { ts } {
    global TSTAMP
    set TSTAMP $ts
}

#############################################################################
# Other procedures                                                          #
#############################################################################

proc ErrorDialog { s1 s2 } {
    tk_messageBox -icon error -parent . -message $s1 -type ok -title Error
    puts $s2
}

proc Exit {} {exit
    set res [tk_messageBox -icon question -parent . \
	    -message "Realy quit?" -type yesno -title Confirm]

    if { $res=="yes" } {
	puts $fd "g"
	exit }
}

proc HelpWin { what } {
    global HELP
    set frm [dialogHead .helpbox "$what" -width 400 -height 250]
    text $frm.txt
    pack $frm.txt -side top -fill both -padx 10
    $frm.txt insert end $HELP($what)
    dialogTailClose .helpbox {}
}

proc OpenDB {} {
    global VIEW
    # Open database
    # ...
    # Fill folder and tag views
    if [catch {readFolders; readTags} mess] {
	ErrorDialog "Database server connection failed!" "$mess"
	return
    }
    # Activate menus
    .m.file entryconfigure "Open database" -state disabled
    .m.file entryconfigure "Close database" -state normal
    .m.action entryconfigure "Display folder" -state normal
    .m.action entryconfigure "Display folder for tag" -state normal
    .m.action entryconfigure "Display folder for time" -state normal
    .m.view entryconfigure "Visualization limits" -state normal
    .m.view entryconfigure "Update folders" -state normal
    .m.view entryconfigure "Update tags" -state normal
}

proc CloseDB {} {
    global VIEW FOLDERS FSETS TAGS DRAWNTYPE DRAWNFOLDER DRAWNARG
    set FOLDERS ""
    set FSETS ""
    set TAGS ""
    # Fill folder and tag views
    fillFolderView $VIEW(folder)
    fillTagView $VIEW(tag)
    # Activate menus
    .m.file entryconfigure "Open database" -state normal
    .m.file entryconfigure "Close database" -state disabled
    .m.action entryconfigure "Display folder for tag" -state disabled
    .m.action entryconfigure "Display folder for time" -state disabled
    .m.action entryconfigure "Display folder" -state disabled
    .m.view entryconfigure "Visualization limits" -state normal
    .m.view entryconfigure "Update folders" -state disabled
    .m.view entryconfigure "Update tags" -state disabled
    #no updates anylonger
    set DRAWNTYPE ""
    set DRAWNFOLDER ""
    set DRAWNARG ""
}

#############################################################################
# Procedures to build GUI                                                   #
#############################################################################

proc createViews { } {
    global VIEW
    set wa [tixPanedWindow .workarea -orient horizontal]
    set pl [$wa add paneLeft]
    set pr [$wa add paneRight]
    frame .fr
    set VIEW(speedbuttons) [createSpeedButtons .fr]
    set VIEW(showallbutton) [createShowAllButton .fr]
    set lwa [tixPanedWindow .wa -orient vertical -width 250 ]
    set lpu [$lwa add paneUp -size 400]
    set lpd [$lwa add paneDown ]
    pack $lwa -fill both -expand yes
    set VIEW(folder) [createFolderView $lpu]
    pack $VIEW(folder) -fill both -expand yes -padx 5 -pady 5
    set VIEW(tag) [createTagView $lpd]
    pack $VIEW(tag) -fill both -expand yes -padx 5 -pady 5
    set VIEW(object) [createObjectView $pr]
    pack $VIEW(object) -fill both -expand yes -padx 5 -pady 5
    pack $lwa $VIEW(speedbuttons) $VIEW(showallbutton) -fill both -in .fr -expand yes
    pack .fr -fill both -in $pl -expand yes
    pack $wa -fill both -expand yes
}

proc createMenus {} {
    menu .m -tearoff 0
    menu .m.file
    .m.file add command -label "Open database" -command OpenDB
    .m.file add command -label "Close database" -command CloseDB -state disabled
    .m.file add separator
    .m.file add command -label "Exit" -command Exit
    .m add cascade -label "File" -menu .m.file
    menu .m.action
    .m.action add command -label "Display folder for tag" -command hIterObjs -state disabled
    .m.action add command -label "Display folder for time" -command vIterObjs -state disabled
    .m.action add command -label "Display folder" -command aIterObjs -state disabled
    .m add cascade -label "Actions" -menu .m.action
    menu .m.view
    .m.view add command -label "Visualization limits" -command SetupView -state normal
    .m.view add command -label "Zoom In" -command zoomIn -state normal
    .m.view add command -label "Zoom Out" -command zoomOut -state normal
    .m.view add command -label "Past" -command moveLeft -state normal
    .m.view add command -label "Future" -command moveRight -state normal
    .m.view add separator
    .m.view add command -label "Update folders" -command readFolders -state disabled
    .m.view add command -label "Update tags" -command readTags -state disabled
    .m add cascade -label "View" -menu .m.view
    menu .m.help -tearoff 0
    .m.help add command -label "Manual" -command "HelpWin Manual"
    .m.help add command -label "About" -command "HelpWin About"
    .m add cascade -label "Help" -menu .m.help
    . configure -menu .m
}


proc createStatusBar {} {
    frame .bottom
    label .bottom.l1 -relief sunken -width 22 -borderwidth 1 -textvariable SEL_ANYFLD
    label .bottom.l2 -relief sunken -width 22 -borderwidth 1 -textvariable SEL_TAG
    pack .bottom.l1 .bottom.l2 -padx 8 -pady 5 -side left
    pack .bottom -side bottom -fill x -expand no
}

#
# Build GUI
#
createStatusBar
createViews
createMenus
OpenDB

wm protocol . WM_DELETE_WINDO Exit
#
# THE END
#
