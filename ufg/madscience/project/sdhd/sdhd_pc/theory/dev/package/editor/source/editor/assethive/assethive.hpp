// File Line: 53
// RVA: 0x2018F0
void __fastcall UFG::HiveAsset::HiveAsset(
        UFG::HiveAsset *this,
        unsigned __int64 resourceID,
        const char *name,
        const char *display_name,
        const char *type_name,
        const char *file)
{
  unsigned __int64 v10; // rax

  v10 = UFG::qStringHash64(type_name, resourceID);
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mParent = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mChildren[0] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mChildren[1] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mNeighbours[0] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mNeighbours[1] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::HiveAsset>::mBaseNode.mUID = v10;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mUID = 0i64;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mParent = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mChildren[0] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mChildren[1] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mNeighbours[0] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode;
  this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode.mNeighbours[1] = &this->UFG::qTreeNode64<UFG::HiveAsset,UFG::ByName>::mBaseNode;
  this->mAssetID = UFG::qStringHash64(type_name, resourceID);
  this->mResourceID = resourceID;
  UFG::qString::qString(&this->mName, name);
  UFG::qString::qString(&this->mDisplayName, display_name);
  UFG::qString::qString(&this->mTypeName, type_name);
  UFG::qString::qString(&this->mFile, file);
  this->mTags.mNode.mPrev = &this->mTags.mNode;
  this->mTags.mNode.mNext = &this->mTags.mNode;
}

