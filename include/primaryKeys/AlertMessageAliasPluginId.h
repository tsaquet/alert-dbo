/**
 * @file AlertMessageAliasPluginId.h
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

#ifndef ALERTMESSAGEALIASPLUGINID_H
#define	ALERTMESSAGEALIASPLUGINID_H

#include <Wt/Dbo/Dbo>

namespace Echoes
{
  namespace Dbo
  {

    struct AlertMessageAliasPluginId {
        Wt::Dbo::ptr<UserRole> userRole;
        Wt::Dbo::ptr<Plugin> plugin;
        Wt::Dbo::ptr<MediaType> mediaType;

        AlertMessageAliasPluginId(Wt::Dbo::ptr<UserRole> ptrUserRole, Wt::Dbo::ptr<Plugin> ptrPlugin, Wt::Dbo::ptr<MediaType> ptrMediaType)
        : userRole(ptrUserRole), plugin(ptrPlugin), mediaType(ptrMediaType) {
        }

        AlertMessageAliasPluginId() {
        }

        bool operator==(const AlertMessageAliasPluginId& other) const {
            return userRole == other.userRole && plugin == other.plugin && mediaType == other.mediaType;
        }

        bool operator<(const AlertMessageAliasPluginId& other) const {
            if ((userRole < other.userRole) || (plugin < other.plugin) || mediaType < other.mediaType)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const AlertMessageAliasPluginId& pk) {
        return o << "\n    {"
                << "\n        \"plugin_id\": " << pk.plugin.id()
                << ",\n        \"user_role_id\": " << pk.userRole.id()
                << ",\n        \"media_type_id\": " << pk.mediaType.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::AlertMessageAliasPluginId& aapid,
            const std::string& name, int size = -1) {
        field(a, aapid.userRole, TRIGRAM_USER_ROLE ID);
        field(a, aapid.plugin, TRIGRAM_PLUGIN ID);
        field(a, aapid.mediaType, TRIGRAM_MEDIA_TYPE ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::AlertMessageAliasPlugin> : public dbo_default_traits {
        typedef Echoes::Dbo::AlertMessageAliasPluginId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::AlertMessageAliasPluginId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* ALERTMESSAGEALIASPLUGINID_H */
