/* 
 * File:   SearchUnit.h
 * Author: rhi
 *
 * Created on 9 octobre 2012, 10:28
 */

#ifndef SEARCHUNIT_H
#define	SEARCHUNIT_H

#include "Wt/Dbo/Dbo"

#include "tools/MainIncludeFile.h"

#include "primaryKeys/SearchUnitId.h"

class SearchUnit : public Table {
public:
    SearchUnit();
    virtual ~SearchUnit();
    
    static std::string TRIGRAM;
    
    SearchUnitId pk;
    Wt::Dbo::ptr<InformationUnit> informationUnit;
    
    template<class Action>
    void persist(Action& a)
    {   
        
        FIELD_FILLER();
        
        Wt::Dbo::id (a, pk, TRIGRAM_SEARCH_UNIT SEP ID);
        
        Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_SEARCH_UNIT SEP TRIGRAM_INFORMATION_UNIT);
    }
    
    virtual std::string toJSON();
    
private:

};

#endif	/* SEARCHUNIT_H */

