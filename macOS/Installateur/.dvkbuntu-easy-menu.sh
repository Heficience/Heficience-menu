#!/bin/sh
test -f DVKBuntu-Easy-Menu.dmg && rm DVKBuntu-Easy-Menu.dmg
create-dmg \
--volname "DVKBuntu Easy-Menu" \
--volicon "../icons.icns" \
--background "../background.png" \
--window-pos 200 120 \
--window-size 800 400 \
--icon-size 100 \
--icon "dvkbuntu-easy-menu.app" 200 190 \
--hide-extension "dvkbuntu-easy-menu.app" \
--eula ".LICENSE.rtf" \
--app-drop-link 600 185 \
"DVKBuntu-Easy-Menu.dmg" \
"."
