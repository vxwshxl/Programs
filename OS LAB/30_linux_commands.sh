# 30. Linux commands such as mkdir,grep,sed,cal,cat,cd,xclock,oclock,>>(append),ls etc

#!/bin/bash
# mkdir, cd, ls, cat, >, >> (append), grep, sed, cal, xclock, oclock
# Everything runs inside a throwaway folder, so nothing else is touched.

work=$(mktemp -d)

echo "== mkdir: create a directory =="
mkdir "$work/demo"
echo "Created demo/"

echo
echo "== cd: change directory =="
cd "$work/demo"
echo "Now in: $(basename "$PWD")"

echo
echo "== > (write) and >> (append) =="
echo "apple" > fruits.txt
echo "banana" >> fruits.txt
echo "cherry" >> fruits.txt
echo "mango" >> fruits.txt
echo "Wrote 1 line with > and appended 3 with >>"

echo
echo "== ls: list files =="
ls

echo
echo "== cat: show file contents =="
cat fruits.txt

echo
echo "== grep: search for lines containing 'an' =="
grep "an" fruits.txt

echo
echo "== sed: replace 'apple' with 'grape' =="
sed 's/apple/grape/' fruits.txt

echo
echo "== cal: calendar for July 2026 =="
cal 7 2026

echo
echo "== xclock / oclock: graphical clocks (need X11) =="
for clock in xclock oclock
do
    if command -v $clock > /dev/null 2>&1 && [ -n "$DISPLAY" ]
    then
        echo "Starting $clock (close its window to continue)"
        $clock
    else
        echo "$clock: not available here (install x11-apps and run inside X11)"
    fi
done

cd /
rm -rf "$work"

# ---------------- Output ----------------
# == mkdir: create a directory ==
# Created demo/
#
# == cd: change directory ==
# Now in: demo
#
# == > (write) and >> (append) ==
# Wrote 1 line with > and appended 3 with >>
#
# == ls: list files ==
# fruits.txt
#
# == cat: show file contents ==
# apple
# banana
# cherry
# mango
#
# == grep: search for lines containing 'an' ==
# banana
# mango
#
# == sed: replace 'apple' with 'grape' ==
# grape
# banana
# cherry
# mango
#
# == cal: calendar for July 2026 ==
#      July 2026
# Su Mo Tu We Th Fr Sa
#           1  2  3  4
#  5  6  7  8  9 10 11
# 12 13 14 15 16 17 18
# 19 20 21 22 23 24 25
# 26 27 28 29 30 31
#
#
# == xclock / oclock: graphical clocks (need X11) ==
# xclock: not available here (install x11-apps and run inside X11)
# oclock: not available here (install x11-apps and run inside X11)
