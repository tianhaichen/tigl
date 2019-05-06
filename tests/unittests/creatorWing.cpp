/*
 * Copyright (C) 2019 CFS Engineering
 *
 * Created: 2019 Malo Drougard <malo.drougard@protonmail.com>
 * Author: Malo Drougard
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

#include "test.h"
#include "tigl.h"
#include "CPACSWing.h"
#include "CPACSWings.h"
#include "CCPACSConfiguration.h"
#include "CCPACSConfigurationManager.h"

class creatorWing : public ::testing::Test
{

protected:
    std::string filename = "";

    TiglCPACSConfigurationHandle tiglHandle = -1;
    TixiDocumentHandle tixiHandle           = -1;

    tigl::CCPACSConfigurationManager* manager = nullptr;
    tigl::CCPACSConfiguration* config         = nullptr;
    tigl::CCPACSWing* wing                    = nullptr;

    void setVariables(std::string inFilename, std::string wingUID)
    {
        unsetVariables();
        filename = inFilename;
        ASSERT_EQ(SUCCESS, tixiOpenDocument(filename.c_str(), &tixiHandle));
        ASSERT_EQ(TIGL_SUCCESS, tiglOpenCPACSConfiguration(tixiHandle, "", &tiglHandle));
        manager = &(tigl::CCPACSConfigurationManager::GetInstance());
        config  = &(manager->GetConfiguration(tiglHandle));
        wing    = &(config->GetWing(wingUID));
    }

    void setWing(std::string wingUID)
    {
        wing = &(config->GetWing(wingUID));
    }

    void unsetVariables()
    {
        filename = "";

        if (tiglHandle > -1) {
            tiglCloseCPACSConfiguration(tiglHandle);
        }
        if (tixiHandle > -1) {
            tixiCloseDocument(tixiHandle);
        }

        tiglHandle = -1;
        tiglHandle = -1;

        manager = nullptr;
        config  = nullptr;
        wing    = nullptr;
    }

    void TearDown()
    {
        unsetVariables();
    }
};

TEST_F(creatorWing, MultipleWings_GetMajorDirection_GetDeepDirection)
{
    // symmetry x-z case
    setVariables("TestData/multiple_wings.xml", "Wing");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Y_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    setWing("W2_RX90");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Z_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    // symmetry x-z case
    setWing("W3_RX40");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Y_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    // no symmetry case
    setWing("W4_RX40b");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Y_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    // symmetry x-z
    // The symmetry prime on the heuristic (So, we get always the correct span)
    setWing("W5_RX60");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Y_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    // no symmetry case
    setWing("W6_RX60b");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Z_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);

    // strang symmetry case (symmetry y-x plane)
    setWing("W7_SymX");
    EXPECT_EQ(wing->GetMajorDirection(), TIGL_Z_AXIS);
    EXPECT_EQ(wing->GetDeepDirection(), TIGL_X_AXIS);
}