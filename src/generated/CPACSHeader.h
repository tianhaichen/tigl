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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <ctime>
#include <string>
#include <tixi.h>
#include "CPACSUpdates.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;

namespace generated
{
    class CPACSCpacs;

    // This class is used in:
    // CPACSCpacs

    /// @brief headerType
    /// 
    /// Header type, containing CPACS dataset description
    /// 
    class CPACSHeader
    {
    public:
        TIGL_EXPORT CPACSHeader(CPACSCpacs* parent);

        TIGL_EXPORT virtual ~CPACSHeader();

        TIGL_EXPORT CPACSCpacs* GetParent();

        TIGL_EXPORT const CPACSCpacs* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetCreator() const;
        TIGL_EXPORT virtual void SetCreator(const std::string& value);

        TIGL_EXPORT virtual const std::time_t& GetTimestamp() const;
        TIGL_EXPORT virtual void SetTimestamp(const std::time_t& value);

        TIGL_EXPORT virtual const std::string& GetVersion() const;
        TIGL_EXPORT virtual void SetVersion(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetCpacsVersion() const;
        TIGL_EXPORT virtual void SetCpacsVersion(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSUpdates>& GetUpdates() const;
        TIGL_EXPORT virtual boost::optional<CPACSUpdates>& GetUpdates();

        TIGL_EXPORT virtual CPACSUpdates& GetUpdates(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveUpdates();

    protected:
        CPACSCpacs* m_parent;

        /// Name of CPACS dataset
        std::string                   m_name;

        /// Description of CPACS dataset
        boost::optional<std::string>  m_description;

        /// Creator of initial CPACS dataset
        std::string                   m_creator;

        /// Timestamp of initial CPACS dataset creation
        std::time_t                   m_timestamp;

        /// Version of initial CPACS dataset
        std::string                   m_version;

        /// CPACS version that the dataset is valid to. The element is optional, since data sets 
        /// can be valid for several CPACS versions. However, we strongly recommend to assign data sets to a
        /// specific CPACS version as far as possible, especially since some tools and libraries (e.g. TiGL) 
        /// require this specification.
        boost::optional<std::string>  m_cpacsVersion;

        boost::optional<CPACSUpdates> m_updates;

    private:
        CPACSHeader(const CPACSHeader&) = delete;
        CPACSHeader& operator=(const CPACSHeader&) = delete;

        CPACSHeader(CPACSHeader&&) = delete;
        CPACSHeader& operator=(CPACSHeader&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSHeader = generated::CPACSHeader;
using CCPACSCpacs = generated::CPACSCpacs;
} // namespace tigl
