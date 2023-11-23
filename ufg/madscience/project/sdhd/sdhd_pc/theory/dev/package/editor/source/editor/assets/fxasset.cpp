// File Line: 11
// RVA: 0x146D9E0
__int64 UFG::Editor::_dynamic_initializer_for__gFxAssetFactory__()
{
  UFG::Editor::FxAssetFactory::FxAssetFactory(&UFG::Editor::gFxAssetFactory);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gFxAssetFactory__);
}

// File Line: 15
// RVA: 0x201740
void __fastcall UFG::Editor::FxAssetFactory::FxAssetFactory(UFG::Editor::FxAssetFactory *this)
{
  unsigned __int64 v2; // rax
  UFG::AssetHive *v3; // rax

  v2 = UFG::qStringHash64("EffectSystem", 0xFFFFFFFFFFFFFFFFui64);
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = v2;
  this->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::HiveAssetFactory::`vftable;
  UFG::qString::qString(&this->mTypeName, "EffectSystem");
  v3 = UFG::AssetHive::Instance();
  UFG::qTree64Base::Add(&v3->mFactories.mTree, &this->mBaseNode);
  this->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::Editor::FxAssetFactory::`vftable;
}

