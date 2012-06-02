#ifndef PROBE_H
#define PROBE_H

#include <Wt/Dbo/Dbo>

#include "ProbeId.h"
#include "Table.h"

#include "Unit.h"
#include "Organization.h"

#include "Plugin.h"

#include "Information.h"
#include "HistoricalValue.h"
#include "Value.h"

#include "WidgetType.h"
#include "Widget.h"

#include "UnitType.h"

#include "Tab.h"
#include "TabVersion.h"
#include "TabWidgetAssociation.h"

#include "Addon.h"

class Organization;
class Value;
class HistoricalValue;

class Probe : public Table
{
    public:
        Probe();
        virtual ~Probe();

        ProbeId pk;

        Wt::Dbo::collection<Wt::Dbo::ptr<Value> > values;
        Wt::Dbo::collection<Wt::Dbo::ptr<HistoricalValue> > historicalValues;

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::id (a, pk, "PRIMARY_KEY");

            Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             "VPR");
            Wt::Dbo::hasMany(a,
                             historicalValues,
                             Wt::Dbo::ManyToOne,
                             "HPR");
        };

    protected:
    private:
};

#endif // PROBE_H
