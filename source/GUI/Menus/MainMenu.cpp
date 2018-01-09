/*
* NEWorld: A free game with similar rules to Minecraft.
* Copyright (C) 2017-2018 NEWorld Team
*
* This file is part of NEWorld.
* NEWorld is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* NEWorld is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with NEWorld.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Menus.h"

namespace Menus {
    class MainMenu : public GUI::Form {
    private:
        GUI::imagebox title;
        GUI::button startbtn, optionsbtn, quitbtn, info;

        void onLoad() override {
            title = GUI::imagebox(0.0f, 1.0f, 0.5f, 1.0f, tex_title, -256, 256, 20, 276, 0.5, 0.5, 0.0, 0.0);
            startbtn = GUI::button(GetStrbyKey("NEWorld.main.start"), -200, 200, 280, 312, 0.5, 0.5, 0.0, 0.0);
            optionsbtn = GUI::button(GetStrbyKey("NEWorld.main.options"), -200, -3, 318, 352, 0.5, 0.5, 0.0, 0.0);
            quitbtn = GUI::button(GetStrbyKey("NEWorld.main.exit"), 3, 200, 318, 352, 0.5, 0.5, 0.0, 0.0);
            info = GUI::button("i", 210, 250, 318, 352, 0.5, 0.5, 0.0, 0.0);
            registerControls(5, &title, &startbtn, &optionsbtn, &info, &quitbtn);
        }

        void onUpdate() override {
            AudioSystem::SpeedOfSound = AudioSystem::Air_SpeedOfSound;
            EFX::EAXprop = Generic;
            EFX::UpdateEAXprop();
            float Pos[] = {0.0f, 0.0f, 0.0f};
            AudioSystem::Update(Pos, false, false, Pos, false, false);
            if (startbtn.clicked) worldmenu();
            if (gamebegin) GUI::PopPage();
            if (optionsbtn.clicked) {
                options();
                startbtn.text = GetStrbyKey("NEWorld.main.start");
                optionsbtn.text = GetStrbyKey("NEWorld.main.options");
                quitbtn.text = GetStrbyKey("NEWorld.main.exit");
            }
            if (info.clicked) Information();
            if (quitbtn.clicked) exit(0);
        }
    };
}

GUI::Form* GUI::GetMain() { return new Menus::MainMenu; }