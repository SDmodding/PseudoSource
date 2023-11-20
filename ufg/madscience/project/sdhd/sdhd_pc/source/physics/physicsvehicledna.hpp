// File Line: 30
// RVA: 0x448390
void __fastcall UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef(UFG::BaseVehiclePhysicsDef *this, MemImageLoadFlag f)
{
  UFG::BaseVehiclePhysicsDef *v2; // rsi
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdi
  unsigned __int64 v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qBaseNodeRB *v6; // rbx
  char *v7; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v8; // [rsp+60h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v8 = &this->mHandles;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::BaseVehiclePhysicsDef::`vftable';
  this->chassis_physicsProperties.mText.mData.mFlags = 2;
  v5 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  v6 = (UFG::qBaseNodeRB *)v5;
  if ( v5 )
  {
    v5->mNext = 0i64;
    v5[1].mNext = 0i64;
    v5[2].mNext = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  v6->mUID = UFG::qStringHash32(v7, 0xFFFFFFFF);
  v6[1].mParent = (UFG::qBaseNodeRB *)v3->mBaseNode.mUID;
  UFG::qBaseTreeRB::Add(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v6);
}

// File Line: 226
// RVA: 0x448AC0
void __fastcall UFG::CarPhysicsDef::CarPhysicsDef(UFG::CarPhysicsDef *this, MemImageLoadFlag f)
{
  UFG::CarPhysicsDef *v2; // rbx

  v2 = this;
  UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef((UFG::BaseVehiclePhysicsDef *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::`vftable';
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WheeledVehiclePhysicsDef::`vftable';
  v2->torqueTable.mData.mFlags = 2;
  v2->drivetrain_gearRatioTable.mData.mFlags = 2;
  v2->drivetrain_upshiftTable.mData.mFlags = 2;
  v2->drivetrain_downshiftTable.mData.mFlags = 2;
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CarPhysicsDef,UFG::WheeledVehiclePhysicsDef>::`vftable';
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CarPhysicsDef::`vftable';
}

// File Line: 250
// RVA: 0x448480
void __fastcall UFG::BikePhysicsDef::BikePhysicsDef(UFG::BikePhysicsDef *this, MemImageLoadFlag f)
{
  UFG::BikePhysicsDef *v2; // rbx

  v2 = this;
  UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef((UFG::BaseVehiclePhysicsDef *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::`vftable';
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WheeledVehiclePhysicsDef::`vftable';
  v2->torqueTable.mData.mFlags = 2;
  v2->drivetrain_gearRatioTable.mData.mFlags = 2;
  v2->drivetrain_upshiftTable.mData.mFlags = 2;
  v2->drivetrain_downshiftTable.mData.mFlags = 2;
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::`vftable';
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::BikePhysicsDef::`vftable';
}

