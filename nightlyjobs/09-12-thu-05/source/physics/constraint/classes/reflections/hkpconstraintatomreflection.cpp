// File Line: 116
// RVA: 0x15CEAA0
hkClassEnum *dynamic_initializer_for__hkpConstraintAtomClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpConstraintAtomAtomTypeEnum;
  hkpConstraintAtomClass_Members.m_enum = hkpConstraintAtomAtomTypeEnum;
  return result;
}

// File Line: 133
// RVA: 0x15CEA30
void dynamic_initializer_for__hkpConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpConstraintAtomClass,
    "hkpConstraintAtom",
    0i64,
    2,
    0i64,
    0,
    &hkpConstraintAtomEnums,
    3,
    &hkpConstraintAtomClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 136
// RVA: 0xD44980
hkClass *__fastcall hkpConstraintAtom::staticClass()
{
  return &hkpConstraintAtomClass;
}

// File Line: 143
// RVA: 0xD44B50
void __fastcall finishLoadedObjecthkpConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 149
// RVA: 0xD44B60
void __fastcall cleanupLoadedObjecthkpConstraintAtom(void *p)
{
  ;
}

// File Line: 212
// RVA: 0x15CF0D0
void dynamic_initializer_for__hkpSetupStabilizationAtomClass__()
{
  hkClass::hkClass(
    &hkpSetupStabilizationAtomClass,
    "hkpSetupStabilizationAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpSetupStabilizationAtomClass_Members,
    4,
    &hkpSetupStabilizationAtom_Default,
    0i64,
    0,
    2u);
}

// File Line: 215
// RVA: 0xD44990
hkClass *__fastcall hkpSetupStabilizationAtom::staticClass()
{
  return &hkpSetupStabilizationAtomClass;
}

// File Line: 222
// RVA: 0xD44B70
void __fastcall finishLoadedObjecthkpSetupStabilizationAtom(void *p, int finishing)
{
  ;
}

// File Line: 228
// RVA: 0xD44B80
void __fastcall cleanupLoadedObjecthkpSetupStabilizationAtom(void *p)
{
  ;
}

// File Line: 265
// RVA: 0x15CE690
void dynamic_initializer_for__hkp3dAngConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkp3dAngConstraintAtomClass,
    "hkp3dAngConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkp3dAngConstraintAtomClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 268
// RVA: 0xD449A0
hkClass *__fastcall hkp3dAngConstraintAtom::staticClass()
{
  return &hkp3dAngConstraintAtomClass;
}

// File Line: 275
// RVA: 0xD44B90
void __fastcall finishLoadedObjecthkp3dAngConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 281
// RVA: 0xD44BA0
void __fastcall cleanupLoadedObjecthkp3dAngConstraintAtom(void *p)
{
  ;
}

// File Line: 343
// RVA: 0x15CEB20
void dynamic_initializer_for__hkpDeformableLinConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpDeformableLinConstraintAtomClass,
    "hkpDeformableLinConstraintAtom",
    &hkpConstraintAtomClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpDeformableLinConstraintAtomClass_Members,
    5,
    &hkpDeformableLinConstraintAtom_Default,
    0i64,
    0,
    1u);
}

// File Line: 346
// RVA: 0xD449B0
hkClass *__fastcall hkpDeformableLinConstraintAtom::staticClass()
{
  return &hkpDeformableLinConstraintAtomClass;
}

// File Line: 353
// RVA: 0xD44BB0
void __fastcall finishLoadedObjecthkpDeformableLinConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 359
// RVA: 0xD44BC0
void __fastcall cleanupLoadedObjecthkpDeformableLinConstraintAtom(void *p)
{
  ;
}

// File Line: 421
// RVA: 0x15CEAB0
void dynamic_initializer_for__hkpDeformableAngConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpDeformableAngConstraintAtomClass,
    "hkpDeformableAngConstraintAtom",
    &hkpConstraintAtomClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpDeformableAngConstraintAtomClass_Members,
    5,
    &hkpDeformableAngConstraintAtom_Default,
    0i64,
    0,
    1u);
}

// File Line: 424
// RVA: 0xD449C0
hkClass *__fastcall hkpDeformableAngConstraintAtom::staticClass()
{
  return &hkpDeformableAngConstraintAtomClass;
}

// File Line: 431
// RVA: 0xD44BD0
void __fastcall finishLoadedObjecthkpDeformableAngConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 437
// RVA: 0xD44BE0
void __fastcall cleanupLoadedObjecthkpDeformableAngConstraintAtom(void *p)
{
  ;
}

// File Line: 457
// RVA: 0x15CE610
hkClassEnum *dynamic_initializer_for__hkpBallSocketConstraintAtom::Members__()
{
  hkClassEnum *result; // rax

  result = hkpConstraintAtomSolvingMethodEnum;
  hkpBallSocketConstraintAtom::Members.m_enum = hkpConstraintAtomSolvingMethodEnum;
  return result;
}

// File Line: 501
// RVA: 0x15CE8C0
void dynamic_initializer_for__hkpBallSocketConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpBallSocketConstraintAtomClass,
    "hkpBallSocketConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpBallSocketConstraintAtom::Members,
    6,
    &hkpBallSocketConstraintAtom_Default,
    0i64,
    0,
    5u);
}

// File Line: 504
// RVA: 0xD449D0
hkClass *__fastcall hkpBallSocketConstraintAtom::staticClass()
{
  return &hkpBallSocketConstraintAtomClass;
}

// File Line: 511
// RVA: 0xD44BF0
void __fastcall finishLoadedObjecthkpBallSocketConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 517
// RVA: 0xD44C00
void __fastcall cleanupLoadedObjecthkpBallSocketConstraintAtom(void *p)
{
  ;
}

// File Line: 555
// RVA: 0x15CF140
void dynamic_initializer_for__hkpStiffSpringConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpStiffSpringConstraintAtomClass,
    "hkpStiffSpringConstraintAtom",
    &hkpConstraintAtomClass,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkpStiffSpringConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 558
// RVA: 0xD449E0
hkClass *__fastcall hkpStiffSpringConstraintAtom::staticClass()
{
  return &hkpStiffSpringConstraintAtomClass;
}

// File Line: 565
// RVA: 0xD44C10
void __fastcall finishLoadedObjecthkpStiffSpringConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 571
// RVA: 0xD44C20
void __fastcall cleanupLoadedObjecthkpStiffSpringConstraintAtom(void *p)
{
  ;
}

// File Line: 609
// RVA: 0x15CEFF0
void dynamic_initializer_for__hkpSetLocalTransformsConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpSetLocalTransformsConstraintAtomClass,
    "hkpSetLocalTransformsConstraintAtom",
    &hkpConstraintAtomClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpSetLocalTransformsConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 612
// RVA: 0xD449F0
hkClass *__fastcall hkpSetLocalTransformsConstraintAtom::staticClass()
{
  return &hkpSetLocalTransformsConstraintAtomClass;
}

// File Line: 619
// RVA: 0xD44C30
void __fastcall finishLoadedObjecthkpSetLocalTransformsConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 625
// RVA: 0xD44C40
void __fastcall cleanupLoadedObjecthkpSetLocalTransformsConstraintAtom(void *p)
{
  ;
}

// File Line: 663
// RVA: 0x15CF060
void dynamic_initializer_for__hkpSetLocalTranslationsConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpSetLocalTranslationsConstraintAtomClass,
    "hkpSetLocalTranslationsConstraintAtom",
    &hkpConstraintAtomClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpSetLocalTranslationsConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 666
// RVA: 0xD44A00
hkClass *__fastcall hkpSetLocalTranslationsConstraintAtom::staticClass()
{
  return &hkpSetLocalTranslationsConstraintAtomClass;
}

// File Line: 673
// RVA: 0xD44C50
void __fastcall finishLoadedObjecthkpSetLocalTranslationsConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 679
// RVA: 0xD44C60
void __fastcall cleanupLoadedObjecthkpSetLocalTranslationsConstraintAtom(void *p)
{
  ;
}

// File Line: 717
// RVA: 0x15CEF80
void dynamic_initializer_for__hkpSetLocalRotationsConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpSetLocalRotationsConstraintAtomClass,
    "hkpSetLocalRotationsConstraintAtom",
    &hkpConstraintAtomClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpSetLocalRotationsConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 720
// RVA: 0xD44A10
hkClass *__fastcall hkpSetLocalRotationsConstraintAtom::staticClass()
{
  return &hkpSetLocalRotationsConstraintAtomClass;
}

// File Line: 727
// RVA: 0xD44C70
void __fastcall finishLoadedObjecthkpSetLocalRotationsConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 733
// RVA: 0xD44C80
void __fastcall cleanupLoadedObjecthkpSetLocalRotationsConstraintAtom(void *p)
{
  ;
}

// File Line: 771
// RVA: 0x15CEDC0
void dynamic_initializer_for__hkpOverwritePivotConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpOverwritePivotConstraintAtomClass,
    "hkpOverwritePivotConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpOverwritePivotConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 774
// RVA: 0xD44A20
hkClass *__fastcall hkpOverwritePivotConstraintAtom::staticClass()
{
  return &hkpOverwritePivotConstraintAtomClass;
}

// File Line: 781
// RVA: 0xD44C90
void __fastcall finishLoadedObjecthkpOverwritePivotConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 787
// RVA: 0xD44CA0
void __fastcall cleanupLoadedObjecthkpOverwritePivotConstraintAtom(void *p)
{
  ;
}

// File Line: 825
// RVA: 0x15CEB90
void dynamic_initializer_for__hkpLinConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpLinConstraintAtomClass,
    "hkpLinConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpLinConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 828
// RVA: 0xD44A30
hkClass *__fastcall hkpLinConstraintAtom::staticClass()
{
  return &hkpLinConstraintAtomClass;
}

// File Line: 835
// RVA: 0xD44CB0
void __fastcall finishLoadedObjecthkpLinConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 841
// RVA: 0xD44CC0
void __fastcall cleanupLoadedObjecthkpLinConstraintAtom(void *p)
{
  ;
}

// File Line: 881
// RVA: 0x15CED50
void dynamic_initializer_for__hkpLinSoftConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpLinSoftConstraintAtomClass,
    "hkpLinSoftConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpLinSoftConstraintAtomClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 884
// RVA: 0xD44A40
hkClass *__fastcall hkpLinSoftConstraintAtom::staticClass()
{
  return &hkpLinSoftConstraintAtomClass;
}

// File Line: 891
// RVA: 0xD44CD0
void __fastcall finishLoadedObjecthkpLinSoftConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 897
// RVA: 0xD44CE0
void __fastcall cleanupLoadedObjecthkpLinSoftConstraintAtom(void *p)
{
  ;
}

// File Line: 937
// RVA: 0x15CEC70
void dynamic_initializer_for__hkpLinLimitConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpLinLimitConstraintAtomClass,
    "hkpLinLimitConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpLinLimitConstraintAtomClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 940
// RVA: 0xD44A50
hkClass *__fastcall hkpLinLimitConstraintAtom::staticClass()
{
  return &hkpLinLimitConstraintAtomClass;
}

// File Line: 947
// RVA: 0xD44CF0
void __fastcall finishLoadedObjecthkpLinLimitConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 953
// RVA: 0xD44D00
void __fastcall cleanupLoadedObjecthkpLinLimitConstraintAtom(void *p)
{
  ;
}

// File Line: 991
// RVA: 0x15CE620
void dynamic_initializer_for__hkp2dAngConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkp2dAngConstraintAtomClass,
    "hkp2dAngConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkp2dAngConstraintAtomClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 994
// RVA: 0xD44A60
hkClass *__fastcall hkp2dAngConstraintAtom::staticClass()
{
  return &hkp2dAngConstraintAtomClass;
}

// File Line: 1001
// RVA: 0xD44D10
void __fastcall finishLoadedObjecthkp2dAngConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1007
// RVA: 0xD44D20
void __fastcall cleanupLoadedObjecthkp2dAngConstraintAtom(void *p)
{
  ;
}

// File Line: 1046
// RVA: 0x15CE700
void dynamic_initializer_for__hkpAngConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpAngConstraintAtomClass,
    "hkpAngConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpAngConstraintAtomClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1049
// RVA: 0xD44A70
hkClass *__fastcall hkpAngConstraintAtom::staticClass()
{
  return &hkpAngConstraintAtomClass;
}

// File Line: 1056
// RVA: 0xD44D30
void __fastcall finishLoadedObjecthkpAngConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1062
// RVA: 0xD44D40
void __fastcall cleanupLoadedObjecthkpAngConstraintAtom(void *p)
{
  ;
}

// File Line: 1124
// RVA: 0x15CE7E0
void dynamic_initializer_for__hkpAngLimitConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpAngLimitConstraintAtomClass,
    "hkpAngLimitConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpAngLimitConstraintAtomClass_Members,
    5,
    &hkpAngLimitConstraintAtom_Default,
    0i64,
    0,
    0);
}

// File Line: 1127
// RVA: 0xD44A80
hkClass *__fastcall hkpAngLimitConstraintAtom::staticClass()
{
  return &hkpAngLimitConstraintAtomClass;
}

// File Line: 1134
// RVA: 0xD44D50
void __fastcall finishLoadedObjecthkpAngLimitConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1140
// RVA: 0xD44D60
void __fastcall cleanupLoadedObjecthkpAngLimitConstraintAtom(void *p)
{
  ;
}

// File Line: 1204
// RVA: 0x15CF1B0
void dynamic_initializer_for__hkpTwistLimitConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpTwistLimitConstraintAtomClass,
    "hkpTwistLimitConstraintAtom",
    &hkpConstraintAtomClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpTwistLimitConstraintAtomClass_Members,
    7,
    &hkpTwistLimitConstraintAtom_Default,
    0i64,
    0,
    0);
}

// File Line: 1207
// RVA: 0xD44A90
hkClass *__fastcall hkpTwistLimitConstraintAtom::staticClass()
{
  return &hkpTwistLimitConstraintAtomClass;
}

// File Line: 1214
// RVA: 0xD44D70
void __fastcall finishLoadedObjecthkpTwistLimitConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1220
// RVA: 0xD44D80
void __fastcall cleanupLoadedObjecthkpTwistLimitConstraintAtom(void *p)
{
  ;
}

// File Line: 1256
// RVA: 0x15CEA20
hkClassEnum *dynamic_initializer_for__hkpConeLimitConstraintAtomClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpConeLimitConstraintAtomMeasurementModeEnum;
  unk_1421100C8 = hkpConeLimitConstraintAtomMeasurementModeEnum;
  return result;
}

// File Line: 1300
// RVA: 0x15CE9A0
void dynamic_initializer_for__hkpConeLimitConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpConeLimitConstraintAtomClass,
    "hkpConeLimitConstraintAtom",
    &hkpConstraintAtomClass,
    32,
    0i64,
    0,
    &hkpConeLimitConstraintAtomEnums,
    1,
    &hkpConeLimitConstraintAtomClass_Members,
    9,
    &hkpConeLimitConstraintAtom_Default,
    0i64,
    0,
    0);
}

// File Line: 1303
// RVA: 0xD44AA0
hkClass *__fastcall hkpConeLimitConstraintAtom::staticClass()
{
  return &hkpConeLimitConstraintAtomClass;
}

// File Line: 1310
// RVA: 0xD44D90
void __fastcall finishLoadedObjecthkpConeLimitConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1316
// RVA: 0xD44DA0
void __fastcall cleanupLoadedObjecthkpConeLimitConstraintAtom(void *p)
{
  ;
}

// File Line: 1357
// RVA: 0x15CE770
void dynamic_initializer_for__hkpAngFrictionConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpAngFrictionConstraintAtomClass,
    "hkpAngFrictionConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpAngFrictionConstraintAtomClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1360
// RVA: 0xD44AB0
hkClass *__fastcall hkpAngFrictionConstraintAtom::staticClass()
{
  return &hkpAngFrictionConstraintAtomClass;
}

// File Line: 1367
// RVA: 0xD44DB0
void __fastcall finishLoadedObjecthkpAngFrictionConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1373
// RVA: 0xD44DC0
void __fastcall cleanupLoadedObjecthkpAngFrictionConstraintAtom(void *p)
{
  ;
}

// File Line: 1417
// RVA: 0x15CE850
void dynamic_initializer_for__hkpAngMotorConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpAngMotorConstraintAtomClass,
    "hkpAngMotorConstraintAtom",
    &hkpConstraintAtomClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpAngMotorConstraintAtomClass_Members,
    8,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 1420
// RVA: 0xD44AC0
hkClass *__fastcall hkpAngMotorConstraintAtom::staticClass()
{
  return &hkpAngMotorConstraintAtomClass;
}

// File Line: 1427
// RVA: 0xD44DD0
void __fastcall finishLoadedObjecthkpAngMotorConstraintAtom(void *p, int finishing)
{
  if ( p )
  {
    *((_WORD *)p + 2) = -1;
    *((_WORD *)p + 3) = -1;
    *((_WORD *)p + 4) = -1;
  }
}

// File Line: 1433
// RVA: 0xD44DF0
void __fastcall cleanupLoadedObjecthkpAngMotorConstraintAtom(void *p)
{
  ;
}

// File Line: 1474
// RVA: 0x15CEF10
void dynamic_initializer_for__hkpRagdollMotorConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpRagdollMotorConstraintAtomClass,
    "hkpRagdollMotorConstraintAtom",
    &hkpConstraintAtomClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpRagdollMotorConstraintAtomClass_Members,
    5,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 1477
// RVA: 0xD44AD0
hkClass *__fastcall hkpRagdollMotorConstraintAtom::staticClass()
{
  return &hkpRagdollMotorConstraintAtomClass;
}

// File Line: 1484
// RVA: 0xD44E00
void __fastcall finishLoadedObjecthkpRagdollMotorConstraintAtom(void *p, int finishing)
{
  if ( p )
  {
    *((_WORD *)p + 2) = -1;
    *((_WORD *)p + 3) = -1;
  }
}

// File Line: 1490
// RVA: 0xD44E20
void __fastcall cleanupLoadedObjecthkpRagdollMotorConstraintAtom(void *p)
{
  ;
}

// File Line: 1530
// RVA: 0x15CEC00
void dynamic_initializer_for__hkpLinFrictionConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpLinFrictionConstraintAtomClass,
    "hkpLinFrictionConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpLinFrictionConstraintAtomClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1533
// RVA: 0xD44AE0
hkClass *__fastcall hkpLinFrictionConstraintAtom::staticClass()
{
  return &hkpLinFrictionConstraintAtomClass;
}

// File Line: 1540
// RVA: 0xD44E30
void __fastcall finishLoadedObjecthkpLinFrictionConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1546
// RVA: 0xD44E40
void __fastcall cleanupLoadedObjecthkpLinFrictionConstraintAtom(void *p)
{
  ;
}

// File Line: 1591
// RVA: 0x15CF220
void dynamic_initializer_for__hkpWheelFrictionConstraintAtomAxleClass__()
{
  hkClass::hkClass(
    &hkpWheelFrictionConstraintAtomAxleClass,
    "hkpWheelFrictionConstraintAtomAxle",
    0i64,
    44,
    0i64,
    0,
    0i64,
    0,
    &hkpWheelFrictionConstraintAtom_AxleClass_Members,
    11,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1594
// RVA: 0xD44AF0
hkClass *__fastcall hkpWheelFrictionConstraintAtom::Axle::staticClass()
{
  return &hkpWheelFrictionConstraintAtomAxleClass;
}

// File Line: 1601
// RVA: 0xD44E50
void __fastcall finishLoadedObjecthkpWheelFrictionConstraintAtomAxle(void *p, int finishing)
{
  ;
}

// File Line: 1607
// RVA: 0xD44E60
void __fastcall cleanupLoadedObjecthkpWheelFrictionConstraintAtomAxle(void *p)
{
  ;
}

// File Line: 1652
// RVA: 0x15CF280
void dynamic_initializer_for__hkpWheelFrictionConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpWheelFrictionConstraintAtomClass,
    "hkpWheelFrictionConstraintAtom",
    &hkpConstraintAtomClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpWheelFrictionConstraintAtomClass_Members,
    9,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1655
// RVA: 0xD44B00
hkClass *__fastcall hkpWheelFrictionConstraintAtom::staticClass()
{
  return &hkpWheelFrictionConstraintAtomClass;
}

// File Line: 1662
// RVA: 0xD44E70
void __fastcall finishLoadedObjecthkpWheelFrictionConstraintAtom(void *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      *(_QWORD *)((char *)p + 20) = 0i64;
      *(_QWORD *)((char *)p + 28) = 0i64;
    }
  }
}

// File Line: 1668
// RVA: 0xD44E90
void __fastcall cleanupLoadedObjecthkpWheelFrictionConstraintAtom(void *p)
{
  ;
}

// File Line: 1710
// RVA: 0x15CECE0
void dynamic_initializer_for__hkpLinMotorConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpLinMotorConstraintAtomClass,
    "hkpLinMotorConstraintAtom",
    &hkpConstraintAtomClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkpLinMotorConstraintAtomClass_Members,
    6,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 1713
// RVA: 0xD44B10
hkClass *__fastcall hkpLinMotorConstraintAtom::staticClass()
{
  return &hkpLinMotorConstraintAtomClass;
}

// File Line: 1720
// RVA: 0xD44EA0
void __fastcall finishLoadedObjecthkpLinMotorConstraintAtom(void *p, int finishing)
{
  if ( p )
  {
    *((_WORD *)p + 2) = -1;
    *((_WORD *)p + 3) = -1;
  }
}

// File Line: 1726
// RVA: 0xD44EC0
void __fastcall cleanupLoadedObjecthkpLinMotorConstraintAtom(void *p)
{
  ;
}

// File Line: 1766
// RVA: 0x15CEE30
void dynamic_initializer_for__hkpPulleyConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpPulleyConstraintAtomClass,
    "hkpPulleyConstraintAtom",
    &hkpConstraintAtomClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpPulleyConstraintAtomClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1769
// RVA: 0xD44B20
hkClass *__fastcall hkpPulleyConstraintAtom::staticClass()
{
  return &hkpPulleyConstraintAtomClass;
}

// File Line: 1776
// RVA: 0xD44ED0
void __fastcall finishLoadedObjecthkpPulleyConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1782
// RVA: 0xD44EE0
void __fastcall cleanupLoadedObjecthkpPulleyConstraintAtom(void *p)
{
  ;
}

// File Line: 1824
// RVA: 0x15CEEA0
void dynamic_initializer_for__hkpRackAndPinionConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpRackAndPinionConstraintAtomClass,
    "hkpRackAndPinionConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpRackAndPinionConstraintAtomClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1827
// RVA: 0xD44B30
hkClass *__fastcall hkpRackAndPinionConstraintAtom::staticClass()
{
  return &hkpRackAndPinionConstraintAtomClass;
}

// File Line: 1834
// RVA: 0xD44EF0
void __fastcall finishLoadedObjecthkpRackAndPinionConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1840
// RVA: 0xD44F00
void __fastcall cleanupLoadedObjecthkpRackAndPinionConstraintAtom(void *p)
{
  ;
}

// File Line: 1882
// RVA: 0x15CE930
void dynamic_initializer_for__hkpCogWheelConstraintAtomClass__()
{
  hkClass::hkClass(
    &hkpCogWheelConstraintAtomClass,
    "hkpCogWheelConstraintAtom",
    &hkpConstraintAtomClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpCogWheelConstraintAtomClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 1885
// RVA: 0xD44B40
hkClass *__fastcall hkpCogWheelConstraintAtom::staticClass()
{
  return &hkpCogWheelConstraintAtomClass;
}

// File Line: 1892
// RVA: 0xD44F10
void __fastcall finishLoadedObjecthkpCogWheelConstraintAtom(void *p, int finishing)
{
  ;
}

// File Line: 1898
// RVA: 0xD44F20
void __fastcall cleanupLoadedObjecthkpCogWheelConstraintAtom(void *p)
{
  ;
}

