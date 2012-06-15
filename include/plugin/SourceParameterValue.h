/* 
 * File:   SourceParameterValue.h
 * Author: tsa
 *
 * Created on 4 juin 2012, 17:25
 */

#ifndef SOURCEPARAMETERVALUE_H
#define	SOURCEPARAMETERVALUE_H

#include "MainIncludeFile.h"
#include "SourceParameterValueId.h"
#include <Wt/Dbo/Dbo>

class SourceParameter;

class SourceParameterValue : public Table {
public:
    SourceParameterValue();
    SourceParameterValue(const SourceParameterValue& orig);
    virtual ~SourceParameterValue();
    
    static std::string TRIGRAM;
    
    Wt::WDateTime deleteTag;          
    std::string value;
   
    
    SourceParameterValueId pk;
    
    //Wt::Dbo::ptr<SourceParameter> sourceParameter;
    
    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::id (a, pk, "PRIMARY_KEY");
        //Wt::Dbo::belongsTo(a, sourceParameter, "SRP");
        mapClassAttributesDates["DELETE"]=this->deleteTag;
        mapClassAttributesStrings["VALUE"]=this->value;         
    }
private:

};

#endif	/* SOURCEPARAMETERVALUE_H */
