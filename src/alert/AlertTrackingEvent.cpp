/* 
 * Alert Tracking Event Table
 * @author ECHOES Technologies (TSA)
 * @date 18/04/2012
 * 
 * THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO ECHOES TECHNOLOGIES SAS
 * AND MAY NOT BE REPRODUCED, PUBLISHED OR DISCLOSED TO OTHERS WITHOUT
 * COMPANY AUTHORIZATION.
 * 
 * COPYRIGHT 2012-2013 BY ECHOES TECHNOLGIES SAS
 * 
 */

#include "alert/AlertTrackingEvent.h"

using namespace std;

namespace Echoes
{
  namespace Dbo
  {
    string AlertTrackingEvent::TRIGRAM(TRIGRAM_ALERT_TRACKING_EVENT);

    AlertTrackingEvent::AlertTrackingEvent()
    {
    }

    AlertTrackingEvent::~AlertTrackingEvent()
    {
    }
  }
}
