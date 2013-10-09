/* 
 * Alert Tracking Table
 * @author ECHOES Technologies (TSA)
 * @date 23/07/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertTracking.h"

std::string AlertTracking::TRIGRAM(TRIGRAM_ALERT_TRACKING);

AlertTracking::AlertTracking()
{
    this->jsonName = "alertTracking";
    //ctor
}

AlertTracking::~AlertTracking()
{

}

std::string AlertTracking::toJSON() const
{
    std::string res = "";
    res += Table::toJSON();
    res += Table::formatJSONForDboPtr(this->alert);
    res += Table::formatJSONForDboPtr(this->mediaValue);
   
    res += Table::formatJSONForDboCollection(this->alertTrackingEvents, "alert_tracking_event" , false);
    
    res += "}";
    return res;
}

