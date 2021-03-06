/**
 * @file FilterParameterValueId.h
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

#ifndef FILTERPARAMETERVALUEID_H
#define	FILTERPARAMETERVALUEID_H

namespace Echoes
{
  namespace Dbo
  {

    class FilterParameter;
    class FilterParameterValue;

    struct FilterParameterValueId {
        Wt::Dbo::ptr<FilterParameter> filterParameter;
        Wt::Dbo::ptr<Filter> filter;

        FilterParameterValueId(Wt::Dbo::ptr<FilterParameter> filterParameter, Wt::Dbo::ptr<Filter> filter)
        : filterParameter(filterParameter), filter(filter) {
        }

        FilterParameterValueId() {
        }

        bool operator==(const FilterParameterValueId& other) const {
            return filterParameter == other.filterParameter && filter == other.filter;
        }

        bool operator<(const FilterParameterValueId& other) const {
            if (filterParameter < other.filterParameter)
                return true;
            else
                return false;
        }
    };

    inline std::ostream& operator<<(std::ostream& o, const FilterParameterValueId& pk) {
        // return o << "(" << pk.filterParameter << ")";
        return o << "\n    {"
                << "\n        \"filter_id\": " << pk.filter.id()
                << ",\n        \"filter_parameter_id\": " << pk.filterParameter.id()
                << "\n    }";
    }

  }
}

namespace Wt
{
  namespace Dbo
  {

    template <class Action>
    void field(Action& a, Echoes::Dbo::FilterParameterValueId& fpvid,
            const std::string& name, int size = -1) {
        field(a, fpvid.filter, TRIGRAM_FILTER ID);
        field(a, fpvid.filterParameter, TRIGRAM_FILTER_PARAMETER ID);
    }

    template<>
    struct dbo_traits<Echoes::Dbo::FilterParameterValue> : public dbo_default_traits {
        typedef Echoes::Dbo::FilterParameterValueId IdType;

        static IdType invalidId() {
            return Echoes::Dbo::FilterParameterValueId();
        }

        static const char *surrogateIdField() {
            return 0;
        }
    };
  }
}

#endif	/* FILTERPARAMETERVALUEID_H */
