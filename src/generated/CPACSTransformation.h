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
#include <CCPACSPoint.h>
#include <CCPACSPointAbsRel.h>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CreateIfNotExists.h"
#include "CTiglError.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSDuct;
class CCPACSEnginePosition;
class CCPACSEnginePylon;
class CCPACSFuselage;
class CCPACSFuselageSectionElement;
class CCPACSFuselageSection;
class CCPACSExternalObject;
class CCPACSGenericSystem;
class CCPACSNacelleSection;
class CCPACSRotor;
class CCPACSRotorHinge;
class CCPACSWing;
class CCPACSWingSectionElement;
class CCPACSWingSection;

namespace generated
{
    // This class is used in:
    // CPACSDuct
    // CPACSEnginePosition
    // CPACSEnginePylon
    // CPACSFuselage
    // CPACSFuselageElement
    // CPACSFuselageSection
    // CPACSGenericGeometricComponent
    // CPACSGenericSystem
    // CPACSNacelleSection
    // CPACSRotor
    // CPACSRotorHubHinge
    // CPACSWing
    // CPACSWingElement
    // CPACSWingSection

    /// @brief transformationType
    /// 
    /// Transformation type, containing a set of
    /// transformations. The order of the transformations is scaling
    /// -> rotation -> translation, and they are executed in this
    /// order. Any of them can be omitted; it will be replaced by its
    /// defaults.
    /// Transformations are always executed relative to the
    /// child not the parent. I.e. a scaling does not have an influence
    /// on the parent item. For example in the outer geometry of a wing
    /// the element scaling does not influence the section. Scaling does
    /// also not effect rotation and translation.
    /// 
    class CPACSTransformation : public CTiglOptUIDObject
    {
    public:
        TIGL_EXPORT CPACSTransformation(CCPACSDuct* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSEnginePosition* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSEnginePylon* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSFuselage* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSFuselageSectionElement* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSFuselageSection* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSExternalObject* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSGenericSystem* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSNacelleSection* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSRotor* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSRotorHinge* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSWing* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSWingSectionElement* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSTransformation(CCPACSWingSection* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSTransformation();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
#ifdef HAVE_STDIS_SAME
            static_assert(std::is_same<P, CCPACSDuct>::value || std::is_same<P, CCPACSEnginePosition>::value || std::is_same<P, CCPACSEnginePylon>::value || std::is_same<P, CCPACSFuselage>::value || std::is_same<P, CCPACSFuselageSectionElement>::value || std::is_same<P, CCPACSFuselageSection>::value || std::is_same<P, CCPACSExternalObject>::value || std::is_same<P, CCPACSGenericSystem>::value || std::is_same<P, CCPACSNacelleSection>::value || std::is_same<P, CCPACSRotor>::value || std::is_same<P, CCPACSRotorHinge>::value || std::is_same<P, CCPACSWing>::value || std::is_same<P, CCPACSWingSectionElement>::value || std::is_same<P, CCPACSWingSection>::value, "template argument for P is not a parent class of CPACSTransformation");
#endif
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
#ifdef HAVE_STDIS_SAME
            static_assert(std::is_same<P, CCPACSDuct>::value || std::is_same<P, CCPACSEnginePosition>::value || std::is_same<P, CCPACSEnginePylon>::value || std::is_same<P, CCPACSFuselage>::value || std::is_same<P, CCPACSFuselageSectionElement>::value || std::is_same<P, CCPACSFuselageSection>::value || std::is_same<P, CCPACSExternalObject>::value || std::is_same<P, CCPACSGenericSystem>::value || std::is_same<P, CCPACSNacelleSection>::value || std::is_same<P, CCPACSRotor>::value || std::is_same<P, CCPACSRotorHinge>::value || std::is_same<P, CCPACSWing>::value || std::is_same<P, CCPACSWingSectionElement>::value || std::is_same<P, CCPACSWingSection>::value, "template argument for P is not a parent class of CPACSTransformation");
#endif
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSPoint>& GetScaling() const;
        TIGL_EXPORT virtual boost::optional<CCPACSPoint>& GetScaling();

        TIGL_EXPORT virtual const boost::optional<CCPACSPoint>& GetRotation() const;
        TIGL_EXPORT virtual boost::optional<CCPACSPoint>& GetRotation();

        TIGL_EXPORT virtual const boost::optional<CCPACSPointAbsRel>& GetTranslation() const;
        TIGL_EXPORT virtual boost::optional<CCPACSPointAbsRel>& GetTranslation();

        TIGL_EXPORT virtual CCPACSPoint& GetScaling(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveScaling();

        TIGL_EXPORT virtual CCPACSPoint& GetRotation(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRotation();

        TIGL_EXPORT virtual CCPACSPointAbsRel& GetTranslation(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveTranslation();

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        boost::optional<std::string>       m_uID;

        /// Scaling data default: 1,1,1. Those parameters
        /// describe the scaling of the x-, y-, and z-axis.
        boost::optional<CCPACSPoint>       m_scaling;

        /// Rotation data default: 0,0,0. The rotation
        /// angles are the three Euler angles to describe the orientation of
        /// the coordinate system. The order is allways xyz in CPACS.
        /// Therefore the first rotation is around the x-axis, the second
        /// rotation is around the rotated y-axis (y') and the third
        /// rotation is around the two times rotated z-axis (z'').
        boost::optional<CCPACSPoint>       m_rotation;

        /// Translation data default: 0,0,0. Translations
        /// can either be made absolute in the global coordinate system
        /// (absGlobal), absolute in the local Coordinate system (absLocal)
        /// or relative (relative), normalized with the maximum dimensions
        /// of the parent.
        boost::optional<CCPACSPointAbsRel> m_translation;

    private:
        CPACSTransformation(const CPACSTransformation&) = delete;
        CPACSTransformation& operator=(const CPACSTransformation&) = delete;

        CPACSTransformation(CPACSTransformation&&) = delete;
        CPACSTransformation& operator=(CPACSTransformation&&) = delete;
    };
} // namespace generated

// CPACSTransformation is customized, use type CCPACSTransformation directly
} // namespace tigl
