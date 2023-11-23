// File Line: 30
// RVA: 0x448390
void __fastcall UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef(UFG::BaseVehiclePhysicsDef *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdi
  unsigned __int64 mUID; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::qBaseNodeRB *v6; // rbx
  char *Name; // rax

  v3 = &this->UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject>;
  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::BaseVehiclePhysicsDef,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::BaseVehiclePhysicsDef::`vftable;
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
  Name = UFG::qReflectObject::GetName(this);
  v6->mUID = UFG::qStringHash32(Name, 0xFFFFFFFF);
  v6[1].mParent = (UFG::qBaseNodeRB *)v3->mBaseNode.mUID;
  UFG::qBaseTreeRB::Add(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v6);
}

// File Line: 226
// RVA: 0x448AC0
void __fastcall UFG::CarPhysicsDef::CarPhysicsDef(UFG::CarPhysicsDef *this, MemImageLoadFlag f)
{
  UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef(this, f);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WheeledVehiclePhysicsDef::`vftable;
  this->torqueTable.mData.mFlags = 2;
  this->drivetrain_gearRatioTable.mData.mFlags = 2;
  this->drivetrain_upshiftTable.mData.mFlags = 2;
  this->drivetrain_downshiftTable.mData.mFlags = 2;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::CarPhysicsDef,UFG::WheeledVehiclePhysicsDef>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::CarPhysicsDef::`vftable;
}

// File Line: 250
// RVA: 0x448480
void __fastcall UFG::BikePhysicsDef::BikePhysicsDef(UFG::BikePhysicsDef *this, MemImageLoadFlag f)
{
  UFG::BaseVehiclePhysicsDef::BaseVehiclePhysicsDef(this, f);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::WheeledVehiclePhysicsDef,UFG::BaseVehiclePhysicsDef>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::WheeledVehiclePhysicsDef::`vftable;
  this->torqueTable.mData.mFlags = 2;
  this->drivetrain_gearRatioTable.mData.mFlags = 2;
  this->drivetrain_upshiftTable.mData.mFlags = 2;
  this->drivetrain_downshiftTable.mData.mFlags = 2;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::BikePhysicsDef,UFG::WheeledVehiclePhysicsDef>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::BikePhysicsDef::`vftable;
}

