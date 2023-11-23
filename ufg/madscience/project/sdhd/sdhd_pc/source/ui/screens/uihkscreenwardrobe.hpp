// File Line: 36
// RVA: 0x5C82B0
void __fastcall UFG::UIHKWardrobeItemInfo::UIHKWardrobeItemInfo(UFG::UIHKWardrobeItemInfo *this)
{
  this->trackerIndex = 0;
  UFG::qString::qString(&this->title);
  UFG::qString::qString(&this->description);
  UFG::qString::qString(&this->brand);
  UFG::qString::qString(&this->clothingBuffSetTitle);
  UFG::qString::qString(&this->clothingBuffSetIcon);
  UFG::qString::qString(&this->clothingBuffSetDesc);
  UFG::qString::qString(&this->discountPercentStr);
  UFG::qString::qString(&this->itemBuffSetTitle);
  UFG::qString::qString(&this->itemBuffSetIcon);
  UFG::qString::qString(&this->itemBuffSetDesc);
  *(_QWORD *)&this->price = 0i64;
  *(_QWORD *)&this->discountPercent = 0i64;
  *(_QWORD *)&this->faceAdjustment = 0i64;
  this->bHasClothingSetPants = 0;
}

