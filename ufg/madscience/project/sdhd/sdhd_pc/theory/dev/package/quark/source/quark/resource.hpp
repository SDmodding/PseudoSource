// File Line: 182
// RVA: 0x1FCA20
void __fastcall UFG::qOffset64<unsigned long *>::operator=(UFG::qOffset64<UFG::qPropertySet *> *this, void *target)
{
  __int64 v2; // [rsp+0h] [rbp-18h]

  if ( target )
    v2 = (_BYTE *)target - (_BYTE *)this;
  else
    v2 = 0i64;
  this->mOffset = v2;
}

// File Line: 186
// RVA: 0x5AF00
void __fastcall UFG::qOffset64<unsigned long *>::Set(UFG::qOffset64<unsigned long *> *this, void *target)
{
  if ( target )
    this->mOffset = (_BYTE *)target - (_BYTE *)this;
  else
    this->mOffset = 0i64;
}

// File Line: 200
// RVA: 0x28160
char *__fastcall UFG::qOffset64<unsigned char *>::Get(UFG::qOffset64<unsigned char *> *this, __int64 offset)
{
  char *result; // rax

  result = (char *)this->mOffset;
  if ( this->mOffset )
    result = &result[offset + (_QWORD)this];
  return result;
}

// File Line: 203
// RVA: 0x29B0
unsigned int *__fastcall UFG::qOffset64<unsigned long *>::operator unsigned long *(UFG::qOffset64<unsigned long *> *this)
{
  unsigned int *result; // rax

  result = (unsigned int *)this->mOffset;
  if ( this->mOffset )
    result = (unsigned int *)((char *)result + (_QWORD)this);
  return result;
}

// File Line: 298
// RVA: 0x3CD0
_BOOL8 __fastcall CAkVPLSrcNode::MustRelocateAnalysisDataOnMediaRelocation(CAkVPLSrcNode *this)
{
  return this->m_pAnalysisData != 0i64;
}

// File Line: 326
// RVA: 0x1ECC10
void __fastcall UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>(UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource> *this)
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mPrev);
}

// File Line: 328
// RVA: 0x8D6C0
void __fastcall UFG::qTypedResourceHandle<2161242425,Illusion::MaterialTable>::~qTypedResourceHandle<2161242425,Illusion::MaterialTable>(UFG::qTypedResourceHandle<2161242425,Illusion::MaterialTable> *this)
{
  UFG::qTypedResourceHandle<2161242425,Illusion::MaterialTable> *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax

  v1 = this;
  v2 = `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x80D1F139);
    `UFG::qGetResourceInventory<Illusion::MaterialTable>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mPrev);
}

// File Line: 336
// RVA: 0x3C00
void __fastcall UFG::qTypedResourceHandle<968624766,UFG::RigResource>::Init(UFG::qTypedResourceHandle<968624766,UFG::RigResource> *this, unsigned int name_uid, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceData *v4; // rbx
  unsigned int v5; // edi
  UFG::qTypedResourceHandle<968624766,UFG::RigResource> *v6; // rsi
  UFG::qResourceWarehouse *v7; // rax

  inventory = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  v4 = resource_data;
  v5 = name_uid;
  v6 = this;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = inventory;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mPrev, 0x39BC0A7Eu, v5, v4, inventory);
}

// File Line: 337
// RVA: 0x1A10
void __fastcall UFG::qTypedResourceHandle<2729299319,Illusion::Model>::Init(UFG::qTypedResourceHandle<2729299319,Illusion::Model> *this, unsigned int name_uid)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  UFG::qTypedResourceHandle<2729299319,Illusion::Model> *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  v2 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  v3 = name_uid;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mPrev, 0xA2ADCD77, v3, v2);
}

// File Line: 366
// RVA: 0x2910
void __fastcall UFG::qGenericResourceHandle::~qGenericResourceHandle(UFG::qGenericResourceHandle *this)
{
  UFG::qGenericResourceHandle *v1; // rbx

  v1 = this;
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&this->mPrev);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mPrev);
}

// File Line: 556
// RVA: 0x8DAC0
void __fastcall UFG::qResourceFileHandle::~qResourceFileHandle(UFG::qResourceFileHandle *this)
{
  UFG::qResourceFileHandle *v1; // rbx

  v1 = this;
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&this->mPrev);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mPrev);
}

// File Line: 828
// RVA: 0x1EBAB0
UFG::qResourceInventory *__fastcall UFG::qGetResourceInventory<UFG::qPropertySetResource>(unsigned int typeUID)
{
  UFG::qResourceWarehouse *v1; // rax
  unsigned int type_uid; // [rsp+30h] [rbp+8h]

  type_uid = typeUID;
  if ( !`UFG::qGetResourceInventory<UFG::qPropertySetResource>'::`2'::result )
  {
    v1 = UFG::qResourceWarehouse::Instance();
    `UFG::qGetResourceInventory<UFG::qPropertySetResource>'::`2'::result = UFG::qResourceWarehouse::GetInventory(
                                                                             v1,
                                                                             type_uid);
  }
  return `UFG::qGetResourceInventory<UFG::qPropertySetResource>'::`2'::result;
}

