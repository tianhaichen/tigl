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
#include "CPACSDuct.h"
#include "CPACSDucts.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSDuct::CPACSDuct(CPACSDucts* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_transformation(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr)
        , m_sections(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr)
        , m_segments(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSDuct::~CPACSDuct()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
        }
    }

    const CPACSDucts* CPACSDuct::GetParent() const
    {
        return m_parent;
    }

    CPACSDucts* CPACSDuct::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSDuct::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSDuct::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSDuct::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSDuct::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSDuct::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read attribute symmetry
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
            m_symmetry = stringToTiglSymmetryAxis(tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element parentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
            m_parentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            if (m_parentUID->empty()) {
                LOG(WARNING) << "Optional element parentUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_parentUID->empty()) m_uidMgr->RegisterReference(*m_parentUID, *this);
        }

        // read element transformation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
            m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
        }
        else {
            LOG(ERROR) << "Required element transformation is missing at xpath " << xpath;
        }

        // read element sections
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sections")) {
            m_sections.ReadCPACS(tixiHandle, xpath + "/sections");
        }
        else {
            LOG(ERROR) << "Required element sections is missing at xpath " << xpath;
        }

        // read element positionings
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/positionings")) {
            m_positionings = boost::in_place(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr);
            try {
                m_positionings->ReadCPACS(tixiHandle, xpath + "/positionings");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read positionings at xpath " << xpath << ": " << e.what();
                m_positionings = boost::none;
            }
        }

        // read element segments
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/segments")) {
            m_segments.ReadCPACS(tixiHandle, xpath + "/segments");
        }
        else {
            LOG(ERROR) << "Required element segments is missing at xpath " << xpath;
        }

        // read element structure
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structure")) {
            m_structure = boost::in_place(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr);
            try {
                m_structure->ReadCPACS(tixiHandle, xpath + "/structure");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read structure at xpath " << xpath << ": " << e.what();
                m_structure = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSDuct::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write attribute symmetry
        if (m_symmetry) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "symmetry");
            }
        }

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element parentUID
        if (m_parentUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/parentUID", *m_parentUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/parentUID");
            }
        }

        // write element transformation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
        m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");

        // write element sections
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sections");
        m_sections.WriteCPACS(tixiHandle, xpath + "/sections");

        // write element positionings
        if (m_positionings) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/positionings");
            m_positionings->WriteCPACS(tixiHandle, xpath + "/positionings");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/positionings")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/positionings");
            }
        }

        // write element segments
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/segments");
        m_segments.WriteCPACS(tixiHandle, xpath + "/segments");

        // write element structure
        if (m_structure) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structure");
            m_structure->WriteCPACS(tixiHandle, xpath + "/structure");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/structure")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/structure");
            }
        }

    }

    const std::string& CPACSDuct::GetUID() const
    {
        return m_uID;
    }

    void CPACSDuct::SetUID(const std::string& value)
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

    const boost::optional<TiglSymmetryAxis>& CPACSDuct::GetSymmetry() const
    {
        return m_symmetry;
    }

    void CPACSDuct::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
    {
        m_symmetry = value;
    }

    const std::string& CPACSDuct::GetName() const
    {
        return m_name;
    }

    void CPACSDuct::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSDuct::GetDescription() const
    {
        return m_description;
    }

    void CPACSDuct::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<std::string>& CPACSDuct::GetParentUID() const
    {
        return m_parentUID;
    }

    void CPACSDuct::SetParentUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_parentUID && !m_parentUID->empty()) m_uidMgr->TryUnregisterReference(*m_parentUID, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_parentUID = value;
    }

    const CCPACSTransformation& CPACSDuct::GetTransformation() const
    {
        return m_transformation;
    }

    CCPACSTransformation& CPACSDuct::GetTransformation()
    {
        return m_transformation;
    }

    const CCPACSFuselageSections& CPACSDuct::GetSections() const
    {
        return m_sections;
    }

    CCPACSFuselageSections& CPACSDuct::GetSections()
    {
        return m_sections;
    }

    const boost::optional<CCPACSPositionings>& CPACSDuct::GetPositionings() const
    {
        return m_positionings;
    }

    boost::optional<CCPACSPositionings>& CPACSDuct::GetPositionings()
    {
        return m_positionings;
    }

    const CCPACSFuselageSegments& CPACSDuct::GetSegments() const
    {
        return m_segments;
    }

    CCPACSFuselageSegments& CPACSDuct::GetSegments()
    {
        return m_segments;
    }

    const boost::optional<CPACSDuctStructure>& CPACSDuct::GetStructure() const
    {
        return m_structure;
    }

    boost::optional<CPACSDuctStructure>& CPACSDuct::GetStructure()
    {
        return m_structure;
    }

    CCPACSPositionings& CPACSDuct::GetPositionings(CreateIfNotExistsTag)
    {
        if (!m_positionings)
            m_positionings = boost::in_place(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr);
        return *m_positionings;
    }

    void CPACSDuct::RemovePositionings()
    {
        m_positionings = boost::none;
    }

    CPACSDuctStructure& CPACSDuct::GetStructure(CreateIfNotExistsTag)
    {
        if (!m_structure)
            m_structure = boost::in_place(reinterpret_cast<CCPACSDuct*>(this), m_uidMgr);
        return *m_structure;
    }

    void CPACSDuct::RemoveStructure()
    {
        m_structure = boost::none;
    }

    const CTiglUIDObject* CPACSDuct::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSDuct::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_parentUID && *m_parentUID == oldUid) {
            m_parentUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
