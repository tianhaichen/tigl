// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSGenericSystem;
class CCPACSACSystems;

namespace generated
{
    // This class is used in:
    // CPACSSystems

    /// @brief genericSystemsType
    /// 
    /// Node for geometrical layout of system components
    /// based on simple geometric shapes
    /// 
    class CPACSGenericSystems
    {
    public:
        TIGL_EXPORT CPACSGenericSystems(CCPACSACSystems* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSGenericSystems();

        TIGL_EXPORT CCPACSACSystems* GetParent();

        TIGL_EXPORT const CCPACSACSystems* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSGenericSystem>>& GetGenericSystems() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSGenericSystem>>& GetGenericSystems();

        TIGL_EXPORT virtual CCPACSGenericSystem& AddGenericSystem();
        TIGL_EXPORT virtual void RemoveGenericSystem(CCPACSGenericSystem& ref);

    protected:
        CCPACSACSystems* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSGenericSystem>> m_genericSystems;

    private:
        CPACSGenericSystems(const CPACSGenericSystems&) = delete;
        CPACSGenericSystems& operator=(const CPACSGenericSystems&) = delete;

        CPACSGenericSystems(CPACSGenericSystems&&) = delete;
        CPACSGenericSystems& operator=(CPACSGenericSystems&&) = delete;
    };
} // namespace generated

// CPACSGenericSystems is customized, use type CCPACSGenericSystems directly
} // namespace tigl
