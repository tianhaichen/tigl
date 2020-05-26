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

#include <cassert>
#include "CCPACSAircraftModel.h"
#include "CCPACSRotorcraftModel.h"
#include "CPACSSystems.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSystems::CPACSSystems(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSAircraftModel);
    }

    CPACSSystems::CPACSSystems(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotorcraftModel);
    }

    CPACSSystems::~CPACSSystems()
    {
    }

    const CTiglUIDObject* CPACSSystems::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSAircraftModel>()) {
                return GetParent<CCPACSAircraftModel>();
            }
            if (IsParent<CCPACSRotorcraftModel>()) {
                return GetParent<CCPACSRotorcraftModel>();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSSystems::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSAircraftModel>()) {
                return GetParent<CCPACSAircraftModel>();
            }
            if (IsParent<CCPACSRotorcraftModel>()) {
                return GetParent<CCPACSRotorcraftModel>();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSSystems::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSystems::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSystems::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element genericSystems
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/genericSystems")) {
            m_genericSystems = boost::in_place(reinterpret_cast<CCPACSACSystems*>(this), m_uidMgr);
            try {
                m_genericSystems->ReadCPACS(tixiHandle, xpath + "/genericSystems");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read genericSystems at xpath " << xpath << ": " << e.what();
                m_genericSystems = boost::none;
            }
        }

    }

    void CPACSSystems::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element genericSystems
        if (m_genericSystems) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/genericSystems");
            m_genericSystems->WriteCPACS(tixiHandle, xpath + "/genericSystems");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/genericSystems")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/genericSystems");
            }
        }

    }

    const boost::optional<CCPACSGenericSystems>& CPACSSystems::GetGenericSystems() const
    {
        return m_genericSystems;
    }

    boost::optional<CCPACSGenericSystems>& CPACSSystems::GetGenericSystems()
    {
        return m_genericSystems;
    }

    CCPACSGenericSystems& CPACSSystems::GetGenericSystems(CreateIfNotExistsTag)
    {
        if (!m_genericSystems)
            m_genericSystems = boost::in_place(reinterpret_cast<CCPACSACSystems*>(this), m_uidMgr);
        return *m_genericSystems;
    }

    void CPACSSystems::RemoveGenericSystems()
    {
        m_genericSystems = boost::none;
    }

} // namespace generated
} // namespace tigl
