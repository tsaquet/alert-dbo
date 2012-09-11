#ifndef PACK_H
#define PACK_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class Pack : public Table
{
    public:
        Pack();
        virtual ~Pack();
        
        static std::string TRIGRAM;
        Wt::WString name;
        
        Wt::Dbo::collection<Wt::Dbo::ptr<Option> > option;
        Wt::Dbo::collection<Wt::Dbo::ptr<Organization> > organization;
        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["NAME"]=&this->name;                       
            FIELD_FILLER();            
                    
            Wt::Dbo::hasMany(a,
                             organization,
                             Wt::Dbo::ManyToOne,
                             "ORG_PCK");
        }
        
    protected:
    private:
};

#endif // PACK_H
