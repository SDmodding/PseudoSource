// File Line: 26
// RVA: 0x1494D30
__int64 dynamic_initializer_for__AudioTrackSurfaceDetection::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackSurfaceDetection", 0xFFFFFFFF);
  AudioTrackSurfaceDetection::sClassNameUID = result;
  return result;
}

// File Line: 40
// RVA: 0x2DE0E0
void __fastcall AudioTrackSurfaceDetection::AudioTrackSurfaceDetection(AudioTrackSurfaceDetection *this)
{
  ITrack::ITrack(this, AudioTrackSurfaceDetection::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSurfaceDetection>::`vftable;
  this->m_RtpcVal = 0.0;
  this->m_playPercent = 100.0;
  *(_QWORD *)&this->m_audioTagId[4] = 0i64;
  *(_QWORD *)&this->m_audioTagId[2] = 0i64;
  *(_QWORD *)this->m_audioTagId = 0i64;
  *(_QWORD *)&this->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&this->m_audioTagUID[2] = 0i64;
  *(_QWORD *)this->m_audioTagUID = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSurfaceDetection::`vftable;
  *(_QWORD *)&this->m_Bone = 8i64;
}

// File Line: 45
// RVA: 0x2E3550
void __fastcall AudioTrackSurfaceDetection::~AudioTrackSurfaceDetection(AudioTrackSurfaceDetection *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSurfaceDetection::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 50
// RVA: 0x301CC0
UFG::qSymbolUC *__fastcall AudioTrackSurfaceDetection::GetBoneUID(
        AudioTrackSurfaceDetection *this,
        UFG::qSymbolUC *result)
{
  __int64 v3; // rdx

  if ( (int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v3 = 0i64;
  else
    v3 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 3);
  UFG::qSymbolUC::create_from_string(result, *(const char **)(*(_QWORD *)(v3 + 16) + 8i64 * (unsigned int)this->m_Bone));
  return result;
}

// File Line: 71
// RVA: 0x1495B50
__int64 dynamic_initializer_for__PoliceScannerAudioEventTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PoliceScannerAudioEventTrack", 0xFFFFFFFF);
  PoliceScannerAudioEventTrack::sClassNameUID = result;
  return result;
}

// File Line: 96
// RVA: 0x2E3F40
void __fastcall DialogueTrackBase::~DialogueTrackBase(DialogueTrackBase *this)
{
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable;
}

// File Line: 137
// RVA: 0x3020A0
__int64 __fastcall DialogueTrackBase::GetTag(DialogueTrackBase *this, int listId, char *name)
{
  __int64 v3; // rdi
  unsigned int v4; // ebx
  __int64 v5; // rdx
  EnumList<unsigned long> *v6; // r9
  __int64 v7; // r10
  EnumList<unsigned long> *v8; // r11
  char *v9; // r9
  char v10; // cl
  __int64 v11; // rdx
  __int64 v12; // rcx
  unsigned int *p; // rax
  char *v14; // rdx
  char v15; // al

  v3 = (unsigned int)this->m_dialogueTagId[listId];
  v4 = this->m_dialogueTagUid[listId];
  if ( name )
  {
    v5 = 0i64;
    if ( audioEnum.m_enumLists.size )
    {
      while ( 1 )
      {
        v6 = (int)audioEnum.m_enumLists.size <= 0 ? 0i64 : audioEnum.m_enumLists.p[v5];
        if ( (int)v3 < (signed int)v6->m_enumName.size && v4 == v6->m_uid.p[v3] )
          break;
        if ( ++v5 >= audioEnum.m_enumLists.size )
          goto LABEL_9;
      }
      v9 = v6->m_enumName.p[v3];
      do
      {
        v10 = *v9;
        ++name;
        ++v9;
        *(name - 1) = v10;
      }
      while ( v10 );
    }
    else
    {
LABEL_9:
      v7 = 0i64;
      if ( audioEnum.m_enumLists.size )
      {
        while ( 1 )
        {
          v8 = (int)audioEnum.m_enumLists.size <= 0 ? 0i64 : audioEnum.m_enumLists.p[v7];
          v11 = 0i64;
          v12 = 0i64;
          if ( v8->m_enumName.size )
            break;
LABEL_20:
          if ( ++v7 >= audioEnum.m_enumLists.size )
            return (unsigned int)v3;
        }
        p = v8->m_enumValue.p;
        while ( v4 != *p )
        {
          ++v12;
          v11 = (unsigned int)(v11 + 1);
          ++p;
          if ( v12 >= v8->m_enumName.size )
            goto LABEL_20;
        }
        v14 = v8->m_enumName.p[v11];
        do
        {
          v15 = *v14;
          ++name;
          ++v14;
          *(name - 1) = v15;
        }
        while ( v15 );
      }
    }
  }
  return (unsigned int)v3;
}

// File Line: 185
// RVA: 0x14952D0
__int64 dynamic_initializer_for__DialogueTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrack", 0xFFFFFFFF);
  DialogueTrack::sClassNameUID = result;
  return result;
}

// File Line: 202
// RVA: 0x2DF170
void __fastcall DialogueTrack::DialogueTrack(DialogueTrack *this)
{
  unsigned int *m_dialogueTagUid; // rax
  __int64 v3; // rcx

  ITrack::ITrack(this, DialogueTrack::sClassNameUID);
  this->Track<DialogueTask>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTask>::`vftable;
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable;
  this->m_playPercent = 100.0;
  this->m_priority = 5;
  m_dialogueTagUid = this->m_dialogueTagUid;
  v3 = 3i64;
  do
  {
    *(m_dialogueTagUid - 3) = 0;
    *m_dialogueTagUid++ = 0;
    --v3;
  }
  while ( v3 );
  this->Track<DialogueTask>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&DialogueTrack::`vftable{for `Track<DialogueTask>};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrack::`vftable{for `DialogueTrackBase};
}

// File Line: 206
// RVA: 0x2E3EC0
void __fastcall DialogueTrack::~DialogueTrack(DialogueTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->Track<DialogueTask>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&DialogueTrack::`vftable{for `Track<DialogueTask>};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrack::`vftable{for `DialogueTrackBase};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable;
  this->Track<DialogueTask>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->Track<DialogueTask>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 219
// RVA: 0x14952F0
__int64 dynamic_initializer_for__DialogueTrackPOI::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrackPOI", 0xFFFFFFFF);
  DialogueTrackPOI::sClassNameUID = result;
  return result;
}

// File Line: 234
// RVA: 0x2DF1F0
void __fastcall DialogueTrackPOI::DialogueTrackPOI(DialogueTrackPOI *this)
{
  unsigned int *m_dialogueTagUid; // rax
  __int64 v3; // rcx

  ITrack::ITrack(this, DialogueTrackPOI::sClassNameUID);
  this->Track<DialogueTaskPOI>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTaskPOI>::`vftable;
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable;
  this->m_playPercent = 100.0;
  this->m_priority = 5;
  m_dialogueTagUid = this->m_dialogueTagUid;
  v3 = 3i64;
  do
  {
    *(m_dialogueTagUid - 3) = 0;
    *m_dialogueTagUid++ = 0;
    --v3;
  }
  while ( v3 );
  this->Track<DialogueTaskPOI>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackPOI::`vftable{for `Track<DialogueTaskPOI>};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackPOI::`vftable{for `DialogueTrackBase};
}

// File Line: 239
// RVA: 0x2E3F50
void __fastcall DialogueTrackPOI::~DialogueTrackPOI(DialogueTrackPOI *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->Track<DialogueTaskPOI>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackPOI::`vftable{for `Track<DialogueTaskPOI>};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackPOI::`vftable{for `DialogueTrackBase};
  this->DialogueTrackBase::vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable;
  this->Track<DialogueTaskPOI>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->Track<DialogueTaskPOI>::ITrack::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 252
// RVA: 0x1495310
__int64 dynamic_initializer_for__DialogueTrackWeaponImpact::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrackWeaponImpact", 0xFFFFFFFF);
  DialogueTrackWeaponImpact::sClassNameUID = result;
  return result;
}

// File Line: 265
// RVA: 0x2DF270
void __fastcall DialogueTrackWeaponImpact::DialogueTrackWeaponImpact(DialogueTrackWeaponImpact *this)
{
  unsigned int *m_dialogueTagUid; // rax
  __int64 v3; // rcx

  ITrack::ITrack(this, DialogueTrackWeaponImpact::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTaskWeaponImpact>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackWeaponImpact::`vftable;
  this->m_playPercent = 100.0;
  this->m_priority = 5;
  m_dialogueTagUid = this->m_dialogueTagUid;
  v3 = 2i64;
  do
  {
    *(m_dialogueTagUid - 2) = 0;
    *m_dialogueTagUid++ = 0;
    --v3;
  }
  while ( v3 );
}

// File Line: 276
// RVA: 0x2E3FD0
void __fastcall DialogueTrackWeaponImpact::~DialogueTrackWeaponImpact(DialogueTrackWeaponImpact *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackWeaponImpact::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 312
// RVA: 0x1494FF0
__int64 dynamic_initializer_for__ConversationTrackCreate::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackCreate", 0xFFFFFFFF);
  ConversationTrackCreate::sClassNameUID = result;
  return result;
}

// File Line: 319
// RVA: 0x2DE720
void __fastcall ConversationTrackCreate::ConversationTrackCreate(ConversationTrackCreate *this)
{
  ITrack::ITrack(this, ConversationTrackCreate::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ConversationTaskCreate>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackCreate::`vftable;
  this->m_topic = 0;
}

// File Line: 332
// RVA: 0x1494FD0
__int64 dynamic_initializer_for__ConversationTrackCleanup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackCleanup", 0xFFFFFFFF);
  ConversationTrackCleanup::sClassNameUID = result;
  return result;
}

// File Line: 345
// RVA: 0x1495030
__int64 dynamic_initializer_for__ConversationTrackOperation::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackOperation", 0xFFFFFFFF);
  ConversationTrackOperation::sClassNameUID = result;
  return result;
}

// File Line: 359
// RVA: 0x1495010
__int64 dynamic_initializer_for__ConversationTrackInterrupt::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackInterrupt", 0xFFFFFFFF);
  ConversationTrackInterrupt::sClassNameUID = result;
  return result;
}

