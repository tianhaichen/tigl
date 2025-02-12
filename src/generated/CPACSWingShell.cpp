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
#include "CCPACSWingCSStructure.h"
#include "CPACSWingShell.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingShell::CPACSWingShell(CCPACSWingCSStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_skin(reinterpret_cast<CCPACSWingShell*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingShell::~CPACSWingShell()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CCPACSWingCSStructure* CPACSWingShell::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingCSStructure* CPACSWingShell::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingShell::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSWingShell::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSWingShell::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingShell::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingShell::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element skin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skin")) {
            m_skin.ReadCPACS(tixiHandle, xpath + "/skin");
        }
        else {
            LOG(ERROR) << "Required element skin is missing at xpath " << xpath;
        }

        // read element cells
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cells")) {
            m_cells = boost::in_place(reinterpret_cast<CCPACSWingShell*>(this), m_uidMgr);
            try {
                m_cells->ReadCPACS(tixiHandle, xpath + "/cells");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cells at xpath " << xpath << ": " << e.what();
                m_cells = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSWingShell::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element skin
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/skin");
        m_skin.WriteCPACS(tixiHandle, xpath + "/skin");

        // write element cells
        if (m_cells) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cells");
            m_cells->WriteCPACS(tixiHandle, xpath + "/cells");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cells")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cells");
            }
        }

    }

    const std::string& CPACSWingShell::GetUID() const
    {
        return m_uID;
    }

    void CPACSWingShell::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const CPACSWingSkin& CPACSWingShell::GetSkin() const
    {
        return m_skin;
    }

    CPACSWingSkin& CPACSWingShell::GetSkin()
    {
        return m_skin;
    }

    const boost::optional<CCPACSWingCells>& CPACSWingShell::GetCells() const
    {
        return m_cells;
    }

    boost::optional<CCPACSWingCells>& CPACSWingShell::GetCells()
    {
        return m_cells;
    }

    CCPACSWingCells& CPACSWingShell::GetCells(CreateIfNotExistsTag)
    {
        if (!m_cells)
            m_cells = boost::in_place(reinterpret_cast<CCPACSWingShell*>(this), m_uidMgr);
        return *m_cells;
    }

    void CPACSWingShell::RemoveCells()
    {
        m_cells = boost::none;
    }

} // namespace generated
} // namespace tigl
