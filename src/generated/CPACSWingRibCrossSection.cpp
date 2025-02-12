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
#include "CCPACSWingRibsDefinition.h"
#include "CPACSWingRibCrossSection.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingRibCrossSection::CPACSWingRibCrossSection(CCPACSWingRibsDefinition* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_material(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingRibCrossSection::~CPACSWingRibCrossSection()
    {
    }

    const CCPACSWingRibsDefinition* CPACSWingRibCrossSection::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingRibsDefinition* CPACSWingRibCrossSection::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingRibCrossSection::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSWingRibCrossSection::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSWingRibCrossSection::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingRibCrossSection::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingRibCrossSection::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element material
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/material")) {
            m_material.ReadCPACS(tixiHandle, xpath + "/material");
        }
        else {
            LOG(ERROR) << "Required element material is missing at xpath " << xpath;
        }

        // read element ribRotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
            m_ribRotation = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
            try {
                m_ribRotation->ReadCPACS(tixiHandle, xpath + "/ribRotation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read ribRotation at xpath " << xpath << ": " << e.what();
                m_ribRotation = boost::none;
            }
        }

        // read element ribCell
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribCell")) {
            m_ribCell = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
            try {
                m_ribCell->ReadCPACS(tixiHandle, xpath + "/ribCell");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read ribCell at xpath " << xpath << ": " << e.what();
                m_ribCell = boost::none;
            }
        }

        // read element upperCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
            m_upperCap = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
            try {
                m_upperCap->ReadCPACS(tixiHandle, xpath + "/upperCap");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read upperCap at xpath " << xpath << ": " << e.what();
                m_upperCap = boost::none;
            }
        }

        // read element lowerCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
            m_lowerCap = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
            try {
                m_lowerCap->ReadCPACS(tixiHandle, xpath + "/lowerCap");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read lowerCap at xpath " << xpath << ": " << e.what();
                m_lowerCap = boost::none;
            }
        }

    }

    void CPACSWingRibCrossSection::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element material
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
        m_material.WriteCPACS(tixiHandle, xpath + "/material");

        // write element ribRotation
        if (m_ribRotation) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribRotation");
            m_ribRotation->WriteCPACS(tixiHandle, xpath + "/ribRotation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribRotation");
            }
        }

        // write element ribCell
        if (m_ribCell) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/ribCell");
            m_ribCell->WriteCPACS(tixiHandle, xpath + "/ribCell");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribCell")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/ribCell");
            }
        }

        // write element upperCap
        if (m_upperCap) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/upperCap");
            m_upperCap->WriteCPACS(tixiHandle, xpath + "/upperCap");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/upperCap");
            }
        }

        // write element lowerCap
        if (m_lowerCap) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/lowerCap");
            m_lowerCap->WriteCPACS(tixiHandle, xpath + "/lowerCap");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/lowerCap");
            }
        }

    }

    const CCPACSMaterialDefinition& CPACSWingRibCrossSection::GetMaterial() const
    {
        return m_material;
    }

    CCPACSMaterialDefinition& CPACSWingRibCrossSection::GetMaterial()
    {
        return m_material;
    }

    const boost::optional<CPACSPointX>& CPACSWingRibCrossSection::GetRibRotation() const
    {
        return m_ribRotation;
    }

    boost::optional<CPACSPointX>& CPACSWingRibCrossSection::GetRibRotation()
    {
        return m_ribRotation;
    }

    const boost::optional<CPACSWingRibCell>& CPACSWingRibCrossSection::GetRibCell() const
    {
        return m_ribCell;
    }

    boost::optional<CPACSWingRibCell>& CPACSWingRibCrossSection::GetRibCell()
    {
        return m_ribCell;
    }

    const boost::optional<CPACSCap>& CPACSWingRibCrossSection::GetUpperCap() const
    {
        return m_upperCap;
    }

    boost::optional<CPACSCap>& CPACSWingRibCrossSection::GetUpperCap()
    {
        return m_upperCap;
    }

    const boost::optional<CPACSCap>& CPACSWingRibCrossSection::GetLowerCap() const
    {
        return m_lowerCap;
    }

    boost::optional<CPACSCap>& CPACSWingRibCrossSection::GetLowerCap()
    {
        return m_lowerCap;
    }

    CPACSPointX& CPACSWingRibCrossSection::GetRibRotation(CreateIfNotExistsTag)
    {
        if (!m_ribRotation)
            m_ribRotation = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
        return *m_ribRotation;
    }

    void CPACSWingRibCrossSection::RemoveRibRotation()
    {
        m_ribRotation = boost::none;
    }

    CPACSWingRibCell& CPACSWingRibCrossSection::GetRibCell(CreateIfNotExistsTag)
    {
        if (!m_ribCell)
            m_ribCell = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
        return *m_ribCell;
    }

    void CPACSWingRibCrossSection::RemoveRibCell()
    {
        m_ribCell = boost::none;
    }

    CPACSCap& CPACSWingRibCrossSection::GetUpperCap(CreateIfNotExistsTag)
    {
        if (!m_upperCap)
            m_upperCap = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
        return *m_upperCap;
    }

    void CPACSWingRibCrossSection::RemoveUpperCap()
    {
        m_upperCap = boost::none;
    }

    CPACSCap& CPACSWingRibCrossSection::GetLowerCap(CreateIfNotExistsTag)
    {
        if (!m_lowerCap)
            m_lowerCap = boost::in_place(reinterpret_cast<CCPACSWingRibCrossSection*>(this), m_uidMgr);
        return *m_lowerCap;
    }

    void CPACSWingRibCrossSection::RemoveLowerCap()
    {
        m_lowerCap = boost::none;
    }

} // namespace generated
} // namespace tigl
