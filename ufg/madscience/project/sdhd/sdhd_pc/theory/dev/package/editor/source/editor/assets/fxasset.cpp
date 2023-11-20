// File Line: 11
// RVA: 0x146D9E0
__int64 UFG::Editor::_dynamic_initializer_for__gFxAssetFactory__()
{
  UFG::Editor::FxAssetFactory::FxAssetFactory(&UFG::Editor::gFxAssetFactory);
  return atexit(UFG::Editor::_dynamic_atexit_destructor_for__gFxAssetFactory__);
}

// File Line: 15
// RVA: 0x201740
void __fastcall UFG::Editor::FxAssetFactory::FxAssetFactory(UFG::Editor::FxAssetFactory *this)
{
  UFG::Editor::FxAssetFactory *v1; // rdi
  unsigned __int64 v2; // rax
  UFG::qTreeNode64<UFG::HiveAssetFactory,UFG::HiveAssetFactory> *v3; // rbx
  UFG::AssetHive *v4; // rax

  v1 = this;
  v2 = UFG::qStringHash64("EffectSystem", 0xFFFFFFFFFFFFFFFFui64);
  v3 = (UFG::qTreeNode64<UFG::HiveAssetFactory,UFG::HiveAssetFactory> *)&v1->mBaseNode;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v2;
  v1->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::HiveAssetFactory::`vftable;
  UFG::qString::qString(&v1->mTypeName, "EffectSystem");
  v4 = UFG::AssetHive::Instance();
  UFG::qTree64Base::Add(&v4->mFactories.mTree, &v1->mBaseNode);
  v1->vfptr = (UFG::HiveAssetFactoryVtbl *)&UFG::Editor::FxAssetFactory::`vftable;
}

