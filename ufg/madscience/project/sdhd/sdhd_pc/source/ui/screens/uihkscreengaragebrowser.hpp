// File Line: 46
// RVA: 0x5C41D0
void __fastcall UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(UFG::UIHKGarageVehicleInfo *this)
{
  this->spawnObjectInfo.mUID = -1;
  UFG::qString::qString(&this->title);
  UFG::qString::qString(&this->description);
  UFG::qString::qString(&this->discountPercentStr);
  UFG::qString::qString(&this->texture);
  UFG::qString::qString(&this->brandTexture);
  UFG::qString::qString(&this->tier);
  *(_QWORD *)&this->price = 0i64;
  *(_QWORD *)&this->faceValue = 0i64;
  this->discountPercent = 0;
  *(_WORD *)&this->bOwned = 0;
  this->playerHasEnoughFace = 0;
}

