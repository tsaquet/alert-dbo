#ifndef ALERTCRITERIA_H
#define ALERTCRITERIA_H

#include "Table.h"

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include "AlertType.h"
#include "AlertParam.h"
#include "Alert.h"

class AlertType;
class AlertParam;
class AlertCriteria : public Table
{
    public:
        AlertCriteria();
        virtual ~AlertCriteria();
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertType> > alertTypes;
        Wt::Dbo::collection<Wt::Dbo::ptr<AlertParam> > alertParams;
        
        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::hasMany(a,alertParams,Wt::Dbo::ManyToMany,"TJ_ACR_APA");
            Wt::Dbo::hasMany(a,alertTypes,Wt::Dbo::ManyToMany,"TJ_ATY_ACR");
        }
    protected:
    private:
};

#endif // ALERTCRITERIA_H
