/* 
 * File:   InformationData.h
 * Author: tsa
 *
 * Created on 31 octobre 2013, 16:42
 */

#ifndef INFORMATIONDATA_H
#define	INFORMATIONDATA_H

#include <Wt/Dbo/Dbo>
#include "tools/MainIncludeFile.h"

namespace Echoes
{
  namespace Dbo
  {

    class InformationData : public Table {
    public:
        InformationData();
        InformationData(const InformationData& orig);
        virtual ~InformationData();

        static std::string TRIGRAM;

        Wt::Dbo::collection<Wt::Dbo::ptr<AlertValue> > alertValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationValue> > informationValues;
        Wt::Dbo::collection<Wt::Dbo::ptr<InformationHistoricalValue> > informationHistoricalValues;
        
        Wt::Dbo::ptr<Information> information;
        Wt::Dbo::ptr<Filter> filter;
        Wt::Dbo::ptr<Asset> asset;
        Wt::Dbo::ptr<InformationUnit> informationUnit;
        int filterFieldIndex;

        template<class Action>
        void persist(Action& a) {
            mapClassAttributesInts["FILTER_FIELD_INDEX"] = &this->filterFieldIndex;
            FIELD_FILLER();
            
            Wt::Dbo::belongsTo(a, information, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION);
            Wt::Dbo::belongsTo(a, filter, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_FILTER);
            Wt::Dbo::belongsTo(a, asset, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_ASSET);
            Wt::Dbo::belongsTo(a, informationUnit, TRIGRAM_INFORMATION_DATA SEP TRIGRAM_INFORMATION_UNIT);

            Wt::Dbo::hasMany(a, alertValues, Wt::Dbo::ManyToOne, TRIGRAM_ALERT_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_VALUE SEP TRIGRAM_INFORMATION_DATA);
            Wt::Dbo::hasMany(a, informationHistoricalValues, Wt::Dbo::ManyToOne, TRIGRAM_INFORMATION_HISTORICAL_VALUE SEP TRIGRAM_INFORMATION_DATA);
        }

    private:

    };

  }
}

#endif	/* INFORMATIONDATA_H */
