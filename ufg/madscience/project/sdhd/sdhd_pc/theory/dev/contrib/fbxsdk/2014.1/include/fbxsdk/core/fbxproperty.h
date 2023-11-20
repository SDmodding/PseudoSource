// File Line: 277
// RVA: 0xA3F030
__int64 __fastcall fbxsdk_2014_1::FbxProperty::Get<bool>(fbxsdk_2014_1::FbxProperty *this)
{
  unsigned __int8 v2; // [rsp+38h] [rbp+10h]
  enum fbxsdk_2014_1::EFbxType v3; // [rsp+40h] [rbp+18h]

  v3 = 9;
  fbxsdk_2014_1::FbxProperty::Get(this, &v2, &v3);
  return v2;
}

// File Line: 489
// RVA: 0xA3F0E0
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxProperty::Find(fbxsdk_2014_1::FbxProperty *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v4; // rbx
  const struct fbxsdk_2014_1::FbxPropertyHandle *v5; // rax
  fbxsdk_2014_1::FbxPropertyHandle v7; // [rsp+30h] [rbp-18h]

  v4 = result;
  v5 = fbxsdk_2014_1::FbxPropertyHandle::Find(&this->mPropertyHandle, &v7, pName, pCaseSensitive);
  fbxsdk_2014_1::FbxProperty::FbxProperty(v4, v5);
  fbxsdk_2014_1::FbxPropertyHandle::~FbxPropertyHandle(&v7);
  return v4;
}

// File Line: 498
// RVA: 0xA3F080
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxProperty::Find(fbxsdk_2014_1::FbxProperty *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, fbxsdk_2014_1::FbxDataType *pDataType, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v5; // rbx
  const struct fbxsdk_2014_1::FbxPropertyHandle *v6; // rax
  fbxsdk_2014_1::FbxPropertyHandle v8; // [rsp+40h] [rbp-18h]

  v5 = result;
  v6 = fbxsdk_2014_1::FbxPropertyHandle::Find(
         &this->mPropertyHandle,
         &v8,
         pName,
         &pDataType->mTypeInfoHandle,
         pCaseSensitive);
  fbxsdk_2014_1::FbxProperty::FbxProperty(v5, v6);
  fbxsdk_2014_1::FbxPropertyHandle::~FbxPropertyHandle(&v8);
  return v5;
}

// File Line: 506
// RVA: 0xA3F130
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxProperty::FindHierarchical(fbxsdk_2014_1::FbxProperty *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v4; // rbx
  const struct fbxsdk_2014_1::FbxPropertyHandle *v5; // rax
  fbxsdk_2014_1::FbxPropertyHandle v7; // [rsp+40h] [rbp-18h]

  v4 = result;
  v5 = fbxsdk_2014_1::FbxPropertyHandle::Find(
         &this->mPropertyHandle,
         &v7,
         pName,
         fbxsdk_2014_1::FbxProperty::sHierarchicalSeparator,
         pCaseSensitive);
  fbxsdk_2014_1::FbxProperty::FbxProperty(v4, v5);
  fbxsdk_2014_1::FbxPropertyHandle::~FbxPropertyHandle(&v7);
  return v4;
}

