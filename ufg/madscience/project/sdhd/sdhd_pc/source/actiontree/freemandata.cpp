// File Line: 30
// RVA: 0x148A500
const char *dynamic_initializer_for__sFreemanDataFactoryList__()
{
  const char *result; // rax

  result = MemberMapUnits::sClassName;
  sFreemanDataFactoryList[0].mClassName = MemberMapUnits::sClassName;
  return result;
}

// File Line: 40
// RVA: 0x1488260
__int64 dynamic_initializer_for__gFreemanDataFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gFreemanDataFactory,
    sFreemanDataFactoryList,
    sFreemanDataFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gFreemanDataFactory__);
}

// File Line: 46
// RVA: 0x148A760
__int64 dynamic_initializer_for__unitsEnum__()
{
  TracksEnum<float>::TracksEnum<float>(&unitsEnum, "Global/Act/Units.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__unitsEnum__);
}

// File Line: 48
// RVA: 0x1480610
__int64 dynamic_initializer_for__MemberMapUnits::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapUnits", 0xFFFFFFFF);
  MemberMapUnits::sClassNameUID = result;
  return result;
}

// File Line: 82
// RVA: 0x14805B0
__int64 dynamic_initializer_for__FreemanEnvironmentInfo::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FreemanEnvironmentInfo", 0xFFFFFFFF);
  FreemanEnvironmentInfo::sClassNameUID = result;
  return result;
}

