// File Line: 46
// RVA: 0x5C41D0
void __fastcall UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(UFG::UIHKGarageVehicleInfo *this)
{
  UFG::UIHKGarageVehicleInfo *v1; // rbx

  v1 = this;
  this->spawnObjectInfo.mUID = -1;
  UFG::qString::qString(&this->title);
  UFG::qString::qString(&v1->description);
  UFG::qString::qString(&v1->discountPercentStr);
  UFG::qString::qString(&v1->texture);
  UFG::qString::qString(&v1->brandTexture);
  UFG::qString::qString(&v1->tier);
  *(_QWORD *)&v1->price = 0i64;
  *(_QWORD *)&v1->faceValue = 0i64;
  v1->discountPercent = 0;
  *(_WORD *)&v1->bOwned = 0;
  v1->playerHasEnoughFace = 0;
}

