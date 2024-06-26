//入参检测
#include "detection.h"

bool IsLegalAge(int age){
    return age>=18&&age<=60;
}

bool IsLegalSex(QString sex){
    return sex=="男"||sex=="女";
}

bool IsLegalCredits(int credits){
    return credits>=0;
}

bool IsLegalScore(int score){
    return score>=0&&score<=100;
}
