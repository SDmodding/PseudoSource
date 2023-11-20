// File Line: 26
// RVA: 0x1FF6A0
UFG::qString *__fastcall UFG::PropertySchemaUtils::classNameFromPropSetName(UFG::qString *result, const char *prop_set_name)
{
  UFG::qString text; // [rsp+30h] [rbp-38h]
  UFG::qString *v4; // [rsp+70h] [rbp+8h]

  v4 = result;
  UFG::qString::qString(&text, prop_set_name);
  UFG::qString::ReplaceString(&text, "default-", &customWorldMapCaption, 0);
  UFG::qString::ReplaceString(&text, "-", "_", 0);
  UFG::qString::qString(v4, &text);
  UFG::qString::~qString(&text);
  return v4;
}

// File Line: 49
// RVA: 0x1F39D0
void __fastcall UFG::PropertySchemaUtils::CopyPropertyValue(UFG::qPropertySet *srcPropSet, UFG::qPropertySet *dstPropSet, UFG::qSymbol *propertyName)
{
  char *v3; // ST80_8
  __int16 *v4; // STB0_8
  int *v5; // ST40_8
  char *v6; // ST90_8
  unsigned __int16 *v7; // ST50_8
  unsigned int *v8; // STD0_8
  __int64 *v9; // ST60_8
  unsigned __int64 *v10; // STA0_8
  float *v11; // ST70_8
  UFG::qVector2 *v; // STC0_8
  UFG::qVector3 *v13; // ST28_8
  UFG::qVector4 *v14; // ST30_8
  UFG::qMatrix44 *v15; // ST38_8
  UFG::qTransQuat *v16; // ST48_8
  bool *v17; // ST58_8
  const char *v18; // ST68_8
  UFG::qSymbol *v19; // ST78_8
  UFG::qSymbolUC *v20; // ST88_8
  UFG::qWiseSymbol *v21; // ST98_8
  UFG::qPropertyList *v22; // STA8_8
  UFG::qPropertyList *v23; // STB8_8
  UFG::qPropertySet *v24; // STC8_8
  UFG::qPropertySet *v25; // STD8_8
  UFG::qPropertySet *v26; // [rsp+F0h] [rbp+8h]
  UFG::qPropertySet *v27; // [rsp+F8h] [rbp+10h]
  UFG::qSymbol *propName; // [rsp+100h] [rbp+18h]

  propName = propertyName;
  v27 = dstPropSet;
  v26 = srcPropSet;
  switch ( UFG::qPropertySet::GetPropertyTypeFromName(srcPropSet, propertyName, DEPTH_RECURSE) )
  {
    case 0u:
      v3 = UFG::qPropertySet::Get<signed char>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<signed char>(v27, propName, *v3);
      break;
    case 1u:
      v4 = UFG::qPropertySet::Get<short>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<short>(v27, propName, *v4);
      break;
    case 2u:
      v5 = UFG::qPropertySet::Get<long>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<long>(v27, propName, *v5);
      break;
    case 3u:
      v9 = UFG::qPropertySet::Get<__int64>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<__int64>(v27, propName, *v9);
      break;
    case 5u:
      v6 = UFG::qPropertySet::Get<unsigned char>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned char>(v27, propName, *v6);
      break;
    case 6u:
      v7 = UFG::qPropertySet::Get<unsigned short>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned short>(v27, propName, *v7);
      break;
    case 7u:
      v8 = UFG::qPropertySet::Get<unsigned long>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned long>(v27, propName, *v8);
      break;
    case 8u:
      v10 = UFG::qPropertySet::Get<unsigned __int64>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned __int64>(v27, propName, *v10);
      break;
    case 9u:
      v17 = UFG::qPropertySet::Get<bool>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<bool>(v27, propName, *v17);
      break;
    case 0xAu:
      v11 = UFG::qPropertySet::Get<float>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<float>(v27, propName, *v11);
      break;
    case 0xCu:
      v18 = UFG::qPropertySet::Get<char const *>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<char const *>(v27, propName, v18);
      break;
    case 0x11u:
      v = UFG::qPropertySet::Get<UFG::qVector2>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector2>(v27, propName, v);
      break;
    case 0x12u:
      v13 = UFG::qPropertySet::Get<UFG::qVector3>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector3>(v27, propName, v13);
      break;
    case 0x13u:
      v14 = UFG::qPropertySet::Get<UFG::qVector4>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector4>(v27, propName, v14);
      break;
    case 0x14u:
      v15 = UFG::qPropertySet::Get<UFG::qMatrix44>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qMatrix44>(v27, propName, v15);
      break;
    case 0x16u:
      v19 = UFG::qPropertySet::Get<UFG::qSymbol>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qSymbol>(v27, propName, v19);
      break;
    case 0x17u:
      v20 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qSymbolUC>(v27, propName, v20);
      break;
    case 0x18u:
      v21 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qWiseSymbol>(v27, propName, v21);
      break;
    case 0x19u:
      v22 = UFG::qPropertySet::Get<UFG::qPropertyList>(v26, propName, 0);
      v23 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v22);
      UFG::qPropertySet::Set<UFG::qPropertyList>(v27, propName, v23);
      break;
    case 0x1Au:
      v24 = UFG::qPropertySet::Get<UFG::qPropertySet>(v26, propName, 0);
      v25 = UFG::qPropertySet::Clone(v24);
      UFG::qPropertySet::Set<UFG::qPropertySet>(v27, propName, v25);
      break;
    case 0x1Cu:
      v16 = UFG::qPropertySet::Get<UFG::qTransQuat>(v26, propName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qTransQuat>(v27, propName, v16);
      break;
    default:
      return;
  }
}

// File Line: 118
// RVA: 0x146BE20
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__gOutputSchemaClasses__()
{
  UFG::PropertySchemaUtils::gOutputSchemaClasses.mNode.mPrev = (UFG::qNode<UFG::PropertySchemaUtils::OutputSchemaClass,UFG::PropertySchemaUtils::OutputSchemaClass> *)&UFG::PropertySchemaUtils::gOutputSchemaClasses;
  UFG::PropertySchemaUtils::gOutputSchemaClasses.mNode.mNext = (UFG::qNode<UFG::PropertySchemaUtils::OutputSchemaClass,UFG::PropertySchemaUtils::OutputSchemaClass> *)&UFG::PropertySchemaUtils::gOutputSchemaClasses;
  return atexit(UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__gOutputSchemaClasses__);
}

// File Line: 555
// RVA: 0x146BF80
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassListSchema__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassListSchema, "default-schema-classlist");
  return atexit(UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassListSchema__);
}

// File Line: 556
// RVA: 0x146BFB0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassTypeList__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassTypeList, "ClassTypeList");
  return atexit(UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassTypeList__);
}

// File Line: 557
// RVA: 0x146BFE0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassTypeMask__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassTypeMask, "ClassTypeMask");
  return atexit(UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassTypeMask__);
}

// File Line: 559
// RVA: 0x146BDE0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__gClassTypes__()
{
  UFG::PropertySchemaUtils::gClassTypes.p = 0i64;
  UFG::PropertySchemaUtils::gClassTypes.size = 0;
  UFG::PropertySchemaUtils::gClassTypes.capacity = 0;
  return atexit(UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__gClassTypes__);
}

