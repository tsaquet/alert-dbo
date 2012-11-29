/* 
 * File:   Syslog.h
 * Author: tsa
 *
 * Created on 5 juin 2012, 17:44
 */

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

#ifndef SYSLOGHISTORY_H
#define	SYSLOGHISTORY_H

class SyslogHistory : public Table
{
public:
    SyslogHistory();
    SyslogHistory(const SyslogHistory& orig);
    virtual ~SyslogHistory();

    static std::string TRIGRAM;
    Wt::WString sd;
    Wt::WDateTime rcptDate;  
    Wt::WDateTime sentDate;
    Wt::WString hostname;
    Wt::WString appName;
    Wt::WString msgId;
    int priority;
    int procId;
    
    boost::optional<int> version;
    // state : 0 = pending, 1 = processing, 2 = done
    short state;
    
    Wt::Dbo::ptr<Probe> probe;
    Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > values;
    Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > historicalValues;
        
    template<class Action>
    void persist(Action& a)
    {
        mapClassAttributesStrings["SD"]=&this->sd;  
        mapClassAttributesDates["RCPT_DATE"]=&this->rcptDate;  
        mapClassAttributesDates["SENT_DATE"]=&this->sentDate;
        mapClassAttributesStrings["HOSTNAME"]=&this->hostname;          
        mapClassAttributesStrings["APP_NAME"]=&this->appName;  
        mapClassAttributesStrings["MSG_ID"]=&this->msgId;
        mapClassAttributesInts["PROC_ID"]=&this->procId;
        mapClassAttributesInts["PRI"]=&this->priority;
        mapClassAttributesIntsNn["VERSION"]=&this->version;
        mapClassAttributesShorts["STATE"]=&this->state;
        
        FIELD_FILLER();

        Wt::Dbo::belongsTo(a, probe, TRIGRAM_SYSLOG_HISTORY SEP TRIGRAM_PROBE);
        
        Wt::Dbo::hasMany(a,
                             values,
                             Wt::Dbo::ManyToOne,
                             TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_SYSLOG_HISTORY);
        Wt::Dbo::hasMany(a,
                            historicalValues,
                            Wt::Dbo::ManyToOne,
                            TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_SYSLOG_HISTORY);
            
    }
private:

};

#endif	/* SYSLOGHISTORY_H */
