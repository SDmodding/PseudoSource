// File Line: 36
// RVA: 0x5C82B0
void __fastcall UFG::UIHKWardrobeItemInfo::UIHKWardrobeItemInfo(UFG::UIHKWardrobeItemInfo *this)
{
  UFG::UIHKWardrobeItemInfo *v1; // rbx

  v1 = this;
  this->trackerIndex = 0;
  UFG::qString::qString(&this->title);
  UFG::qString::qString(&v1->description);
  UFG::qString::qString(&v1->brand);
  UFG::qString::qString(&v1->clothingBuffSetTitle);
  UFG::qString::qString(&v1->clothingBuffSetIcon);
  UFG::qString::qString(&v1->clothingBuffSetDesc);
  UFG::qString::qString(&v1->discountPercentStr);
  UFG::qString::qString(&v1->itemBuffSetTitle);
  UFG::qString::qString(&v1->itemBuffSetIcon);
  UFG::qString::qString(&v1->itemBuffSetDesc);
  *(_QWORD *)&v1->price = 0i64;
  *(_QWORD *)&v1->discountPercent = 0i64;
  *(_QWORD *)&v1->faceAdjustment = 0i64;
  v1->bHasClothingSetPants = 0;
}

