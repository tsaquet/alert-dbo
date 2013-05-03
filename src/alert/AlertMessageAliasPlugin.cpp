/* 
 * File:   AlertMessageAliasPlugin.cpp
 * Author: tsa
 * 
 * Created on 25 février 2013, 18:08
 */

#include "alert/AlertMessageAliasPlugin.h"

std::string AlertMessageAliasPlugin::TRIGRAM(TRIGRAM_ALERT_MESSAGE_ALIAS_PLUGIN);

AlertMessageAliasPlugin::AlertMessageAliasPlugin()
{
    this->jsonName = "alert_message_alias_plugin";
}

AlertMessageAliasPlugin::AlertMessageAliasPlugin(const AlertMessageAliasPlugin& orig)
{
}

AlertMessageAliasPlugin::~AlertMessageAliasPlugin()
{
}

std::string AlertMessageAliasPlugin::toJSON()
{
    std::string res = "{\n";
    res += Table::toJSON();
    res += "\"id\" : {" + boost::lexical_cast<std::string>(this->pk) + " }\n";
    res += "}\n";
    return res;
}