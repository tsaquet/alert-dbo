/**
 * @file MainIncludeFile.h
 * @author Thomas Saquet, Florent Poinsaut
 * @date 
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Alert - Dbo is the database objects library, part of the Alert software
 * Copyright (C) 2013-2017
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 * 
 */

#ifndef MAININCLUDEFILE_H
#define	MAININCLUDEFILE_H

#include <Wt/Auth/User>

#include "tools/Table.h"
#include "tools/dboSpecialization.h"
#include "tools/MacroTrigram.h"


#include "user/User.h"
#include "user/UserHierarchy.h"
#include "user/UserProfile.h"
#include "user/UserRole.h"
#include "user/UserField.h"

#include "tools/Constants.h"
//#include "tools/SessionPool.h"

#include "unit/InformationUnit.h"
#include "user/UserHistoricalAction.h"
#include "user/UserValue.h"
#include "user/UserActionType.h"
#include "user/UserRight.h"
#include "user/Space.h"
#include "user/AccessControlList.h"

#include "organization/Organization.h"
#include "organization/OrganizationType.h"
#include "organization/OrganizationValue.h"
#include "organization/OrganizationField.h"

#include "information/Information.h"
#include "information/InformationHistoricalValue.h"
#include "information/InformationValue.h"
#include "information/InformationData.h"

#include "plugin/Plugin.h"
#include "plugin/PluginReference.h"
#include "plugin/PluginData.h"

#include "filter/Filter.h"
#include "filter/FilterType.h"
#include "filter/FilterParameter.h"
#include "filter/FilterParameterValue.h"

//#include "widget/WidgetType.h"
//#include "widget/Widget.h"

#include "unit/InformationUnitType.h"
#include "unit/InformationSubUnit.h"

//#include "widget/Tab.h"
//#include "widget/TabVersion.h"
//#include "TabWidgetAssociation.h"

#include "addon/Addon.h"
#include "addon/AddonCommonPackage.h"
#include "addon/AddonCommonPackageParameter.h"
#include "addon/AddonPackage.h"
#include "addon/AddonPackageParameter.h"

#include "alert/Alert.h"
#include "alert/AlertAcknowledge.h"
#include "alert/AlertCriteria.h"
#include "alert/AlertMediaSpecialization.h"
#include "alert/AlertValue.h"
#include "alert/AlertSequence.h"
#include "alert/AlertTimeSlot.h"
#include "alert/AlertTracking.h"
#include "alert/AlertTrackingEvent.h"
#include "alert/AlertMessageAliasAsset.h"
#include "alert/AlertMessageAliasPlugin.h"
#include "alert/AlertMessageAliasInformation.h"
#include "alert/AlertMessageAliasInformationCriteria.h"

#include "engine/Engine.h"
#include "engine/EngOrg.h"

#include "source/Source.h"
#include "source/SourceParameter.h"
#include "source/SourceParameterValue.h"

#include "asset/Asset.h"
#include "asset/AssetArchitecture.h"
#include "asset/AssetDistribution.h"
#include "asset/AssetRelease.h"

#include "search/Search.h"
#include "search/SearchType.h"
#include "search/SearchParameter.h"
#include "search/SearchParameterValue.h"

#include "information/Syslog.h"

#include "pack/Pack.h"
#include "pack/OptionType.h"
#include "pack/PackOption.h"
#include "pack/Option.h"

#include "probe/Probe.h"
#include "probe/ProbePackage.h"
#include "probe/ProbePackageParameter.h"

#include "media/MediaType.h"
#include "media/Media.h"

#endif	/* MAININCLUDEFILE_H */
