#include "File.h"

bool File::ifFileIsEmpty(CMarkup &xml){

MCD_STR strXML = xml.GetDoc();

if(strXML == "") return true;
else
    return false;

}
