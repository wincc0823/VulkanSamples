/*
 * LunarGravity - lgwindow.hpp
 *
 * Copyright (C) 2017 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

class LgGraphicsEngine;

#include "vulkan/vulkan.h"

class LgWindow {
    public:

        // Create a protected constructor
        LgWindow(const uint32_t width, const uint32_t height, bool fullscreen);

        // We don't want any copy constructors
        LgWindow(const LgWindow &window) = delete;
        LgWindow &operator=(const LgWindow &window) = delete;

        bool QueryWindowSystem(LgGraphicsEngine *pEngine, std::vector<VkExtensionProperties> &ext_props,
                               uint32_t &ext_count, const char** desired_extensions);

        // Make the destructor public
        virtual ~LgWindow();

    protected:
 
   private:
        uint32_t    m_width;
        uint32_t    m_height;
        bool        m_fullscreen;
        LgGraphicsEngine *m_gfx_engine;
};
