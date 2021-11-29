#!/bin/sh
test -f Heficience-Menu.dmg && rm Heficience-Menu.dmg
create-dmg \
--volname "Heficicence Menu" \
--volicon "../icons.icns" \
--background "../background.png" \
--window-pos 200 120 \
--window-size 800 400 \
--icon-size 100 \
--icon "heficience-menu.app" 200 190 \
--hide-extension "heficience-menu.app" \
--eula ".LICENSE.rtf" \
--app-drop-link 600 185 \
"Heficience-Menu.dmg" \
"."
