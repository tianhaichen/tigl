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
#include "CPACSCutOutProfile.h"
#include "CPACSCutOutProfiles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCutOutProfile::CPACSCutOutProfile(CPACSCutOutProfiles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_eta(this, m_uidMgr)
        , m_rotZ(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSCutOutProfile::~CPACSCutOutProfile()
    {
        if (m_uidMgr) {
            if (!m_profileUID.empty()) m_uidMgr->TryUnregisterReference(m_profileUID, *this);
        }
    }

    const CPACSCutOutProfiles* CPACSCutOutProfile::GetParent() const
    {
        return m_parent;
    }

    CPACSCutOutProfiles* CPACSCutOutProfile::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSCutOutProfile::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSCutOutProfile::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSCutOutProfile::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSCutOutProfile::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSCutOutProfile::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element profileUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/profileUID")) {
            m_profileUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/profileUID");
            if (m_profileUID.empty()) {
                LOG(WARNING) << "Required element profileUID is empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_profileUID.empty()) m_uidMgr->RegisterReference(m_profileUID, *this);
        }
        else {
            LOG(ERROR) << "Required element profileUID is missing at xpath " << xpath;
        }

        // read element eta
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta")) {
            m_eta.ReadCPACS(tixiHandle, xpath + "/eta");
        }
        else {
            LOG(ERROR) << "Required element eta is missing at xpath " << xpath;
        }

        // read element rotZ
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotZ")) {
            m_rotZ = tixi::TixiGetElement<double>(tixiHandle, xpath + "/rotZ");
        }
        else {
            LOG(ERROR) << "Required element rotZ is missing at xpath " << xpath;
        }

    }

    void CPACSCutOutProfile::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element profileUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/profileUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/profileUID", m_profileUID);

        // write element eta
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta");
        m_eta.WriteCPACS(tixiHandle, xpath + "/eta");

        // write element rotZ
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotZ");
        tixi::TixiSaveElement(tixiHandle, xpath + "/rotZ", m_rotZ);

    }

    const std::string& CPACSCutOutProfile::GetProfileUID() const
    {
        return m_profileUID;
    }

    void CPACSCutOutProfile::SetProfileUID(const std::string& value)
    {
        if (m_uidMgr) {
            if (!m_profileUID.empty()) m_uidMgr->TryUnregisterReference(m_profileUID, *this);
            if (!value.empty()) m_uidMgr->RegisterReference(value, *this);
        }
        m_profileUID = value;
    }

    const CCPACSEtaIsoLine& CPACSCutOutProfile::GetEta() const
    {
        return m_eta;
    }

    CCPACSEtaIsoLine& CPACSCutOutProfile::GetEta()
    {
        return m_eta;
    }

    const double& CPACSCutOutProfile::GetRotZ() const
    {
        return m_rotZ;
    }

    void CPACSCutOutProfile::SetRotZ(const double& value)
    {
        m_rotZ = value;
    }

    const CTiglUIDObject* CPACSCutOutProfile::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSCutOutProfile::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_profileUID == oldUid) {
            m_profileUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
