/* 
 * File:   AlertTracking.h
 * Author: tsa
 *
 * Created on 23 juillet 2012, 16:31
 */

#ifndef ALERTTRACKING_H
#define	ALERTTRACKING_H

#include <Wt/Dbo/Dbo>

#include "tools/MainIncludeFile.h"

class AlertTracking : public Table
{
    public:
        AlertTracking();
        virtual ~AlertTracking();
        
        static std::string TRIGRAM;
        
        
        std::string senderSrv;
        Wt::WDateTime sendDate;
        std::string receiverSrv;
        Wt::WDateTime receiveDate;
        std::string ackGw;
        std::string ackPort;
        std::string ackId;
        std::string ackEvent;

        Wt::Dbo::ptr<MediaValue> mediaValue;
        Wt::Dbo::ptr<Alert> alert;

        template<class Action>
        void persist(Action& a)
        {
            mapClassAttributesStrings["SENDER_SRV"]=this->senderSrv;
            mapClassAttributesStrings["RECEIVER_SRV"]=this->receiverSrv;
            mapClassAttributesStrings["ACK_GW"]=this->ackGw;
            mapClassAttributesStrings["ACK_PORT"]=this->ackPort;
            mapClassAttributesStrings["ACK_ID"]=this->ackId;
            mapClassAttributesStrings["ACK_EVENT"]=this->ackEvent;
            mapClassAttributesDates["SEND_DATE"]=this->sendDate;
            mapClassAttributesDates["RECEIV_DATE"]=this->receiveDate;
            
            
            FIELD_FILLER();

            Wt::Dbo::belongsTo(a,mediaValue,TRIGRAM_ALERT_TRACKING SEP TRIGRAM_MEDIA_VALUE);
            Wt::Dbo::belongsTo(a,alert,TRIGRAM_ALERT_TRACKING SEP TRIGRAM_ALERT);
        }
    protected:
    private:
};


#endif	/* ALERTTRACKING_H */
