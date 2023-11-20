// File Line: 53
// RVA: 0x2018F0
void __fastcall UFG::HiveAsset::HiveAsset(UFG::HiveAsset *this, unsigned __int64 resourceID, const char *name, const char *display_name, const char *type_name, const char *file)
{
  const char *v6; // rbp
  const char *v7; // rdi
  unsigned __int64 v8; // rbx
  UFG::HiveAsset *v9; // r14
  unsigned __int64 v10; // rax
  UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName> *v11; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v12; // [rsp+58h] [rbp+10h]

  v6 = display_name;
  v7 = name;
  v8 = resourceID;
  v9 = this;
  v10 = UFG::qStringHash64(type_name, resourceID);
  v9->mBaseNode.mParent = &v9->mBaseNode;
  v9->mBaseNode.mChildren[0] = &v9->mBaseNode;
  v9->mBaseNode.mChildren[1] = &v9->mBaseNode;
  v9->mBaseNode.mNeighbours[0] = &v9->mBaseNode;
  v9->mBaseNode.mNeighbours[1] = &v9->mBaseNode;
  v9->mBaseNode.mUID = v10;
  v11 = (UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName> *)&v9->mBaseNode;
  v11->mBaseNode.mUID = 0i64;
  v11->mBaseNode.mParent = &v11->mBaseNode;
  v11->mBaseNode.mChildren[0] = &v11->mBaseNode;
  v11->mBaseNode.mChildren[1] = &v11->mBaseNode;
  v11->mBaseNode.mNeighbours[0] = &v11->mBaseNode;
  v11->mBaseNode.mNeighbours[1] = &v11->mBaseNode;
  v9->mAssetID = UFG::qStringHash64(type_name, v8);
  v9->mResourceID = v8;
  UFG::qString::qString(&v9->mName, v7);
  UFG::qString::qString(&v9->mDisplayName, v6);
  UFG::qString::qString(&v9->mTypeName, type_name);
  UFG::qString::qString(&v9->mFile, file);
  v12 = &v9->mTags;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
}

