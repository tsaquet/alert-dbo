///* 
// * File:   SourceId.h
// * Author: tom
// *
// * Created on 23 avril 2012, 17:35
// */
//
//
//#ifndef SOURCEID_H
//#define	SOURCEID_H
//
//#include <Wt/Dbo/Dbo>
//
//class Plugin;
//class Source;
//
//namespace Echoes
//{
//  namespace Dbo
//  {
//
//    struct SourceId {
//        long long id;
//        Wt::Dbo::ptr<Plugin> plugin;
//
//        SourceId(long long id, Wt::Dbo::ptr<Plugin> ptr)
//        : id(id), plugin(ptr) {
//        }
//
//        SourceId() {
//            id = 0;
//        }
//
//        bool operator==(const SourceId& other) const {
//            return id == other.id && plugin == other.plugin;
//        }
//
//        bool operator<(const SourceId& other) const {
//            if ((id < other.id) || (plugin < other.plugin))
//                return true;
//            else
//                return false;
//        }
//    };
//
//    inline std::ostream& operator<<(std::ostream& o, const SourceId& pk) {
//        //return o << "(" << pk.id << ")" << "(" << pk.plugin << ")";
//        return o << "\"plugin_id\": " << pk.plugin.id() << ",\n\t\t"
//                << "\"source_id\": " << pk.id;
//    }
//
//  }
//}
//
//namespace Wt
//{
//  namespace Dbo
//  {
//
//    template <class Action>
//    void field(Action& a, Echoes::Dbo::SourceId& soid,
//            const std::string& name, int size = -1) {
//        field(a, soid.id, TRIGRAM_SOURCE SEP ID);
//        field(a, soid.plugin, TRIGRAM_PLUGIN SEP ID);
//    }
//
//    template<>
//    struct dbo_traits<Echoes::Dbo::Source> : public dbo_default_traits {
//        typedef Echoes::Dbo::SourceId IdType;
//
//        static IdType invalidId() {
//            return Echoes::Dbo::SourceId();
//        }
//
//        static const char *surrogateIdField() {
//            return 0;
//        }
//    };
//  }
//}
//#endif	/* SOURCEID_H */