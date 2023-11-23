// File Line: 31
// RVA: 0x1524B50
__int64 UFG::GameStat::_dynamic_initializer_for__Symbol_ReservedFMapBool4__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ReservedFMapBool4", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::GameStat::Symbol_ReservedFMapBool4, v0);
  return atexit((int (__fastcall *)())UFG::GameStat::_dynamic_atexit_destructor_for__Symbol_ReservedFMapBool4__);
}

// File Line: 164
// RVA: 0x4A6C50
UFG::qSymbol *__fastcall UFG::GameStat::GetSymbol(UFG::GameStat::TimeStat stat)
{
  return TimeSymbols[stat];
}

// File Line: 167
// RVA: 0x4A6C20
UFG::qSymbol *__fastcall UFG::GameStat::GetSymbol(UFG::GameStat::Int32Stat stat)
{
  return Int32Symbols[stat];
}

// File Line: 169
// RVA: 0x4A6C10
UFG::qSymbol *__fastcall UFG::GameStat::GetSymbol(UFG::GameStat::FloatStat stat)
{
  return FloatSymbols[stat];
}

// File Line: 174
// RVA: 0x4A6C30
UFG::qSymbol *__fastcall UFG::GameStat::GetSymbol(UFG::GameStat::MapBoolStat stat)
{
  return MapBoolSymbols[stat];
}

// File Line: 175
// RVA: 0x4A6C40
UFG::qSymbol *__fastcall UFG::GameStat::GetSymbol(UFG::GameStat::MapInt32Stat stat)
{
  return MapInt32Symbols[stat];
}

// File Line: 182
// RVA: 0x4A6C70
__int64 __fastcall UFG::GameStat::GetTimeStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x76A6FE1A )
  {
    if ( mUID == 1990655514 )
      return 28i64;
    if ( mUID > 0x55F9B88F )
    {
      if ( mUID > 0x617BED62 )
      {
        switch ( mUID )
        {
          case 0x68E1AE1Fu:
            return 29i64;
          case 0x6DC8B6F5u:
            return 11i64;
          case 0x7267E3ADu:
            return 27i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x617BED62u:
            return 7i64;
          case 0x58BA9E56u:
            return 23i64;
          case 0x5C7B83E1u:
            return 24i64;
          case 0x602CCDB8u:
            return 8i64;
        }
      }
    }
    else
    {
      if ( mUID == 1442429071 )
        return 22i64;
      if ( mUID > 0x112E1CEE )
      {
        switch ( mUID )
        {
          case 0x11FEFDE1u:
            return 18i64;
          case 0x41C04346u:
            return 12i64;
          case 0x423CD3E4u:
            return 25i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x112E1CEEu:
            return 15i64;
          case 0x6CF4872u:
            return 6i64;
          case 0x794CA9Bu:
            return 3i64;
          case 0x813D137u:
            return 9i64;
        }
      }
    }
    return 30i64;
  }
  if ( mUID <= 0xC27C72B7 )
  {
    if ( mUID == -1032031561 )
      return 21i64;
    if ( mUID > 0x943B64AB )
    {
      switch ( mUID )
      {
        case 0x9E6252BB:
          return 2i64;
        case 0xAEE592A7:
          return 13i64;
        case 0xC1BD089B:
          return 20i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0x943B64AB:
          return 5i64;
        case 0x7F24C574u:
          return 26i64;
        case 0x8A21C2C4:
          return 17i64;
        case 0x8DA18210:
          return 0i64;
      }
    }
    return 30i64;
  }
  if ( mUID <= 0xDEA06E66 )
  {
    switch ( mUID )
    {
      case 0xDEA06E66:
        return 19i64;
      case 0xCC0B9F9A:
        return 4i64;
      case 0xCE56E9B7:
        return 14i64;
      case 0xD883179F:
        return 10i64;
    }
    return 30i64;
  }
  if ( mUID == -371397617 )
    return 1i64;
  if ( mUID != -139842885 )
    return 30i64;
  return 16i64;
}

// File Line: 196
// RVA: 0x4A3560
UFG::GameStat::IDStat __fastcall UFG::GameStat::GetIDStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x79F594C8 )
  {
    if ( mUID == 2046137544 )
      return 39;
    if ( mUID > 0x55CCB293 )
    {
      if ( mUID > 0x6E30FFA3 )
      {
        switch ( mUID )
        {
          case 0x7077AFA6u:
            return ReservedFCID3;
          case 0x74B6B211u:
            return ReservedFCID2;
          case 0x777E6172u:
            return WeaponStowed;
          case 0x796E702Du:
            return TraceContact;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x6E30FFA3u:
            return ReservedFCID4;
          case 0x570D789Fu:
            return CurrentHeadgear;
          case 0x57AE88F0u:
            return LowerBody;
          case 0x5907D0C9u:
            return Glasses;
          case 0x662A3072u:
            return PlayerWeapon;
        }
      }
    }
    else
    {
      if ( mUID == 1439478419 )
        return 5;
      if ( mUID > 0x2B4BE5C4 )
      {
        switch ( mUID )
        {
          case 0x2CF97BC5u:
            return 20;
          case 0x31747F52u:
            return 17;
          case 0x3A54F2ADu:
            return 29;
          case 0x4465BE11u:
            return 19;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x2B4BE5C4u:
            return 15;
          case 0xDEECCEu:
            return 26;
          case 0xA416151u:
            return 4;
          case 0x12B6D0C6u:
            return 32;
          case 0x25E4D832u:
            return 28;
        }
      }
    }
    return 44;
  }
  if ( mUID <= 0xC32022E6 )
  {
    if ( mUID == -1021304090 )
      return 36;
    if ( mUID > 0xA8245162 )
    {
      switch ( mUID )
      {
        case 0xAE115074:
          return 10;
        case 0xB2ECBBE8:
          return 22;
        case 0xB4803600:
          return 16;
        case 0xB6E20C63:
          return 18;
        case 0xBC98D79C:
          return 6;
      }
    }
    else
    {
      if ( mUID == -1474014878 )
        return 1;
      if ( mUID > 0x9890D3F8 )
      {
        if ( mUID == -1718800341 )
          return 0;
        if ( mUID == -1502042175 )
          return 13;
      }
      else
      {
        switch ( mUID )
        {
          case 0x9890D3F8:
            return 9;
          case 0x7E8F2E15u:
            return 43;
          case 0x892ED5F7:
            return 12;
          case 0x8AE5F6A5:
            return 8;
        }
      }
    }
    return 44;
  }
  if ( mUID <= 0xE500E5B6 )
  {
    switch ( mUID )
    {
      case 0xE500E5B6:
        return 33;
      case 0xC7E13F51:
        return 37;
      case 0xCE63043F:
        return 35;
      case 0xD0BCD271:
        return 23;
      case 0xD17C9299:
        return 14;
      case 0xD9A66F54:
        return 38;
    }
    return 44;
  }
  switch ( mUID )
  {
    case 0xEB2FBC12:
      return 30;
    case 0xF076160C:
      return 3;
    case 0xF7B47158:
      return 21;
    case 0xF926D62D:
      return 25;
  }
  if ( mUID != -109338094 )
    return 44;
  return 27;
}

// File Line: 210
// RVA: 0x4A1960
__int64 __fastcall UFG::GameStat::GetBoolStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x74403A22 )
  {
    if ( mUID == 1950366242 )
      return 43i64;
    if ( mUID > 0x20C7126A )
    {
      if ( mUID > 0x366670BE )
      {
        if ( mUID > 0x61778A4B )
        {
          if ( mUID == 1729748744 )
            return 48i64;
          if ( mUID == 1731961755 )
            return 20i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0x61778A4Bu:
              return 30i64;
            case 0x41BF4FD1u:
              return 54i64;
            case 0x4CB19944u:
              return 50i64;
            case 0x5A60C57Du:
              return 3i64;
          }
        }
      }
      else
      {
        if ( mUID == 912683198 )
          return 17i64;
        if ( mUID > 0x2BCB4A0C )
        {
          if ( mUID == 808081774 )
            return 27i64;
          if ( mUID == 906411777 )
            return 6i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0x2BCB4A0Cu:
              return 51i64;
            case 0x240548DEu:
              return 9i64;
            case 0x24F99179u:
              return 49i64;
            case 0x2620B51Fu:
              return 16i64;
          }
        }
      }
    }
    else
    {
      if ( mUID == 549917290 )
        return 55i64;
      if ( mUID > 0xDF3CB7F )
      {
        if ( mUID > 0x1BE865D0 )
        {
          if ( mUID == 528881124 )
            return 5i64;
          if ( mUID == 543988943 )
            return 26i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0x1BE865D0u:
              return 41i64;
            case 0x10A7D22Cu:
              return 21i64;
            case 0x1718E9EFu:
              return 32i64;
            case 0x1A73A85Cu:
              return 31i64;
          }
        }
      }
      else
      {
        if ( mUID == 234081151 )
          return 37i64;
        if ( mUID > 0x6AD3E5D )
        {
          if ( mUID == 154545853 )
            return 56i64;
          if ( mUID == 161707302 )
            return 4i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0x6AD3E5Du:
              return 14i64;
            case 0xE1178Du:
              return 24i64;
            case 0x42177DDu:
              return 10i64;
            case 0x4BAB556u:
              return 40i64;
          }
        }
      }
    }
    return 58i64;
  }
  if ( mUID <= 0xC5E4C74C )
  {
    if ( mUID == -974862516 )
      return 18i64;
    if ( mUID > 0x9C5652CC )
    {
      if ( mUID > 0xAFB8D3F2 )
      {
        switch ( mUID )
        {
          case 0xB0BD11EA:
            return 42i64;
          case 0xC3A8EE9C:
            return 28i64;
          case 0xC5BFADB3:
            return 52i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xAFB8D3F2:
            return 11i64;
          case 0x9DCED4D3:
            return 57i64;
          case 0xA22FECCA:
            return 33i64;
          case 0xA8803BDB:
            return 0i64;
        }
      }
    }
    else
    {
      if ( mUID == -1672064308 )
        return 47i64;
      if ( mUID > 0x90E9D237 )
      {
        switch ( mUID )
        {
          case 0x92F53DB9:
            return 29i64;
          case 0x94B91469:
            return 19i64;
          case 0x94DFBDAC:
            return 35i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x90E9D237:
            return 39i64;
          case 0x7D900C4Au:
            return 46i64;
          case 0x8CA5D259:
            return 1i64;
          case 0x904A0505:
            return 36i64;
        }
      }
    }
    return 58i64;
  }
  if ( mUID <= 0xE5579D7A )
  {
    if ( mUID == -447242886 )
      return 38i64;
    if ( mUID > 0xD3EE2B3D )
    {
      switch ( mUID )
      {
        case 0xD5A202ED:
          return 15i64;
        case 0xD773748D:
          return 34i64;
        case 0xE32565DE:
          return 22i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0xD3EE2B3D:
          return 25i64;
        case 0xCC4538B0:
          return 45i64;
        case 0xCE3BC16C:
          return 44i64;
        case 0xD30E684E:
          return 53i64;
      }
    }
    return 58i64;
  }
  if ( mUID <= 0xF8F6A97F )
  {
    switch ( mUID )
    {
      case 0xF8F6A97F:
        return 8i64;
      case 0xE5694C0E:
        return 12i64;
      case 0xF363A07F:
        return 23i64;
      case 0xF52F89AF:
        return 13i64;
    }
    return 58i64;
  }
  if ( mUID == -115980979 )
    return 7i64;
  if ( mUID != -53093155 )
    return 58i64;
  return 2i64;
}

// File Line: 224
// RVA: 0x4A3860
__int64 __fastcall UFG::GameStat::GetInt32StatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x7EDEEB53 )
  {
    if ( mUID == 2128538451 )
      return 17i64;
    if ( mUID > 0x4CC8731D )
    {
      if ( mUID > 0x6942DC10 )
      {
        if ( mUID > 0x74BDCF78 )
        {
          if ( mUID > 0x77703E44 )
          {
            switch ( mUID )
            {
              case 0x77C07232u:
                return 100i64;
              case 0x7CE8E052u:
                return 70i64;
              case 0x7EBF7EA0u:
                return 142i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x77703E44u:
                return 28i64;
              case 0x74D5E65Cu:
                return 92i64;
              case 0x74E72B9Fu:
                return 79i64;
              case 0x75CF6BE3u:
                return 156i64;
              case 0x7745B559u:
                return 77i64;
            }
          }
        }
        else
        {
          if ( mUID == 1958596472 )
            return 116i64;
          if ( mUID > 0x6D8B3CFD )
          {
            switch ( mUID )
            {
              case 0x71718F57u:
                return 158i64;
              case 0x719804BEu:
                return 46i64;
              case 0x723CAD5Eu:
                return 154i64;
              case 0x72D09642u:
                return 49i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x6D8B3CFDu:
                return 91i64;
              case 0x6A222B70u:
                return 109i64;
              case 0x6C24F902u:
                return 132i64;
              case 0x6CFDAEF3u:
                return 107i64;
              case 0x6D85D7CEu:
                return 89i64;
            }
          }
        }
      }
      else
      {
        if ( mUID == 1765989392 )
          return 157i64;
        if ( mUID > 0x5A3E7FA5 )
        {
          if ( mUID > 0x5DCC417E )
          {
            switch ( mUID )
            {
              case 0x60E01E55u:
                return 13i64;
              case 0x648856C3u:
                return 74i64;
              case 0x657D4AD9u:
                return 135i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x5DCC417Eu:
                return 36i64;
              case 0x5C22DC1Bu:
                return 6i64;
              case 0x5CD3D792u:
                return 147i64;
              case 0x5CFBDFCBu:
                return 131i64;
              case 0x5DB194C9u:
                return 117i64;
            }
          }
        }
        else
        {
          if ( mUID == 1514045349 )
            return 32i64;
          if ( mUID > 0x58437E48 )
          {
            switch ( mUID )
            {
              case 0x593A9A60u:
                return 38i64;
              case 0x5976035Au:
                return 105i64;
              case 0x59F5EC9Cu:
                return 61i64;
              case 0x5A19A534u:
                return 141i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x58437E48u:
                return 133i64;
              case 0x4FADA70Bu:
                return 27i64;
              case 0x504AD7B0u:
                return 22i64;
              case 0x52D6DE80u:
                return 144i64;
              case 0x54A94B50u:
                return 112i64;
            }
          }
        }
      }
    }
    else
    {
      if ( mUID == 1288205085 )
        return 87i64;
      if ( mUID > 0x21736AA7 )
      {
        if ( mUID > 0x38083CDE )
        {
          if ( mUID > 0x4282CB98 )
          {
            switch ( mUID )
            {
              case 0x437495C3u:
                return 138i64;
              case 0x47DDBE84u:
                return 48i64;
              case 0x4AA11401u:
                return 113i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x4282CB98u:
                return 66i64;
              case 0x3A3339D2u:
                return 60i64;
              case 0x3B49B342u:
                return 15i64;
              case 0x3D26D79Bu:
                return 140i64;
              case 0x413662D1u:
                return 114i64;
            }
          }
        }
        else
        {
          if ( mUID == 940063966 )
            return 150i64;
          if ( mUID > 0x29867C9E )
          {
            switch ( mUID )
            {
              case 0x2A465ED6u:
                return 54i64;
              case 0x2FA23003u:
                return 125i64;
              case 0x30463CA6u:
                return 90i64;
              case 0x3282589Fu:
                return 161i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x29867C9Eu:
                return 83i64;
              case 0x21EE4E5Du:
                return 101i64;
              case 0x23AF8446u:
                return 99i64;
              case 0x25334A02u:
                return 68i64;
              case 0x297DF99Bu:
                return 110i64;
            }
          }
        }
      }
      else
      {
        if ( mUID == 561212071 )
          return 118i64;
        if ( mUID > 0x15ACD467 )
        {
          if ( mUID > 0x1CF65432 )
          {
            switch ( mUID )
            {
              case 0x1E3D2987u:
                return 8i64;
              case 0x1EF1CD29u:
                return 97i64;
              case 0x2000E54Fu:
                return 58i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x1CF65432u:
                return 108i64;
              case 0x15AEB137u:
                return 33i64;
              case 0x18883CF8u:
                return 57i64;
              case 0x1A7BF5B3u:
                return 25i64;
              case 0x1AA357FBu:
                return 42i64;
            }
          }
        }
        else
        {
          if ( mUID == 363648103 )
            return 65i64;
          if ( mUID > 0x6D4BBFB )
          {
            switch ( mUID )
            {
              case 0x7390557u:
                return 39i64;
              case 0xC34F92Bu:
                return 67i64;
              case 0x124425F7u:
                return 56i64;
              case 0x1334905Bu:
                return 69i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x6D4BBFBu:
                return 59i64;
              case 0x1E83BF1u:
                return 162i64;
              case 0x288B8EEu:
                return 44i64;
              case 0x4F03063u:
                return 7i64;
              case 0x67D0141u:
                return 40i64;
            }
          }
        }
      }
    }
    return 163i64;
  }
  if ( mUID <= 0xBEB86394 )
  {
    if ( mUID == -1095212140 )
      return 2i64;
    if ( mUID > 0xA2030C5F )
    {
      if ( mUID > 0xB338FC5C )
      {
        if ( mUID > 0xB723C6CA )
        {
          switch ( mUID )
          {
            case 0xB8DA6EDA:
              return 159i64;
            case 0xB8DC9803:
              return 21i64;
            case 0xBC790A40:
              return 19i64;
            case 0xBE19943B:
              return 53i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0xB723C6CA:
              return 30i64;
            case 0xB3A0E24F:
              return 10i64;
            case 0xB452FEAD:
              return 115i64;
            case 0xB53416E8:
              return 121i64;
            case 0xB5E3402F:
              return 134i64;
            case 0xB65B5CDD:
              return 43i64;
          }
        }
      }
      else
      {
        if ( mUID == -1288111012 )
          return 63i64;
        if ( mUID > 0xAAF600A3 )
        {
          switch ( mUID )
          {
            case 0xAE1B74B2:
              return 104i64;
            case 0xB17992FC:
              return 71i64;
            case 0xB183EF1A:
              return 51i64;
            case 0xB1BBA43A:
              return 155i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0xAAF600A3:
              return 88i64;
            case 0xA2F336A7:
              return 98i64;
            case 0xA471642B:
              return 64i64;
            case 0xA60A8D65:
              return 4i64;
            case 0xA7DA5F19:
              return 35i64;
            case 0xA7EAB3D5:
              return 41i64;
          }
        }
      }
    }
    else
    {
      if ( mUID == -1576858529 )
        return 145i64;
      if ( mUID > 0x96105A26 )
      {
        if ( mUID > 0x9D36B83F )
        {
          switch ( mUID )
          {
            case 0x9DA3E589:
              return 139i64;
            case 0x9F15C635:
              return 52i64;
            case 0x9FE6A896:
              return 128i64;
            case 0xA1CCBAA2:
              return 9i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x9D36B83F:
              return 37i64;
            case 0x99A1028D:
              return 143i64;
            case 0x9B90D91B:
              return 102i64;
            case 0x9C6BA4D3:
              return 148i64;
            case 0x9C7185D3:
              return 20i64;
            case 0x9C745387:
              return 153i64;
          }
        }
      }
      else
      {
        if ( mUID == -1777313242 )
          return 75i64;
        if ( mUID > 0x8EF6865C )
        {
          switch ( mUID )
          {
            case 0x91C55811:
              return 106i64;
            case 0x93432E2D:
              return 23i64;
            case 0x934ABD9F:
              return 26i64;
            case 0x95854F43:
              return 85i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x8EF6865C:
              return 34i64;
            case 0x7F2AB9A8u:
              return 111i64;
            case 0x8374E8D4:
              return 136i64;
            case 0x872F8E14:
              return 120i64;
            case 0x87D70274:
              return 146i64;
            case 0x8D29669D:
              return 80i64;
          }
        }
      }
    }
    return 163i64;
  }
  if ( mUID <= 0xE4B4363F )
  {
    if ( mUID == -457951681 )
      return 82i64;
    if ( mUID > 0xCC1B362B )
    {
      if ( mUID > 0xD9720C2E )
      {
        switch ( mUID )
        {
          case 0xDC4EE01A:
            return 55i64;
          case 0xDE2B96D4:
            return 129i64;
          case 0xE07A6188:
            return 152i64;
          case 0xE32DB12C:
            return 78i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xD9720C2E:
            return 24i64;
          case 0xD133C89D:
            return 86i64;
          case 0xD3140E65:
            return 122i64;
          case 0xD4A3DED9:
            return 95i64;
          case 0xD69D306A:
            return 126i64;
          case 0xD880E439:
            return 137i64;
        }
      }
    }
    else
    {
      if ( mUID == -870631893 )
        return 123i64;
      if ( mUID > 0xC4D582F2 )
      {
        switch ( mUID )
        {
          case 0xC5C5F916:
            return 3i64;
          case 0xC67AFD53:
            return 84i64;
          case 0xC9F15835:
            return 160i64;
          case 0xCB552E4E:
            return 124i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xC4D582F2:
            return 62i64;
          case 0xBF248B3B:
            return 45i64;
          case 0xBFBDF9A3:
            return 73i64;
          case 0xC22BA100:
            return 14i64;
          case 0xC3B9AF25:
            return 5i64;
          case 0xC4769FAF:
            return 96i64;
        }
      }
    }
    return 163i64;
  }
  if ( mUID <= 0xF41648AB )
  {
    if ( mUID == -199866197 )
      return 81i64;
    if ( mUID > 0xEC9632DC )
    {
      switch ( mUID )
      {
        case 0xECCF0E38:
          return 94i64;
        case 0xF1DDFE6A:
          return 0i64;
        case 0xF1FC0263:
          return 31i64;
        case 0xF3025FA4:
          return 93i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0xEC9632DC:
          return 18i64;
        case 0xE6189501:
          return 151i64;
        case 0xE84076C5:
          return 16i64;
        case 0xE94C85BB:
          return 72i64;
        case 0xEA99974E:
          return 1i64;
        case 0xEBBCCC9E:
          return 119i64;
      }
    }
    return 163i64;
  }
  if ( mUID <= 0xFB436A5A )
  {
    switch ( mUID )
    {
      case 0xFB436A5A:
        return 11i64;
      case 0xF4802AC1:
        return 130i64;
      case 0xF73EC33A:
        return 127i64;
      case 0xF96E9138:
        return 29i64;
      case 0xFA113E44:
        return 12i64;
      case 0xFA21856B:
        return 149i64;
    }
    return 163i64;
  }
  switch ( mUID )
  {
    case 0xFB8491DB:
      return 103i64;
    case 0xFC183022:
      return 47i64;
    case 0xFEAB70F4:
      return 50i64;
  }
  if ( mUID != -10053847 )
    return 163i64;
  return 76i64;
}

// File Line: 252
// RVA: 0x4A2A30
__int64 __fastcall UFG::GameStat::GetFloatStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x7CF7C89C )
  {
    if ( mUID == 2096613532 )
      return 110i64;
    if ( mUID > 0x44D0B5FA )
    {
      if ( mUID > 0x64AEAF2C )
      {
        if ( mUID > 0x6ADB650F )
        {
          if ( mUID > 0x6E1A78B8 )
          {
            switch ( mUID )
            {
              case 0x6E35429Bu:
                return 25i64;
              case 0x6EA1BCA2u:
                return 73i64;
              case 0x78103AA0u:
                return 108i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x6E1A78B8u:
                return 19i64;
              case 0x6AF45F2Cu:
                return 24i64;
              case 0x6B7A5300u:
                return 71i64;
              case 0x6D571F9Du:
                return 116i64;
            }
          }
        }
        else
        {
          if ( mUID == 1792763151 )
            return 18i64;
          if ( mUID > 0x67B779F5 )
          {
            switch ( mUID )
            {
              case 0x699B9991u:
                return 22i64;
              case 0x69B3C31Bu:
                return 90i64;
              case 0x6A9AEDC3u:
                return 44i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x67B779F5u:
                return 23i64;
              case 0x66EC11FCu:
                return 104i64;
              case 0x6735894Cu:
                return 27i64;
              case 0x679843D6u:
                return 17i64;
            }
          }
        }
      }
      else
      {
        if ( mUID == 1689169708 )
          return 8i64;
        if ( mUID > 0x5734552A )
        {
          if ( mUID > 0x60724D04 )
          {
            switch ( mUID )
            {
              case 0x62A9F085u:
                return 33i64;
              case 0x62F80EA1u:
                return 136i64;
              case 0x63178CAEu:
                return 31i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x60724D04u:
                return 51i64;
              case 0x59B6F5DEu:
                return 40i64;
              case 0x5BA66378u:
                return 50i64;
              case 0x5D16A26Cu:
                return 130i64;
            }
          }
        }
        else
        {
          if ( mUID == 1463047466 )
            return 42i64;
          if ( mUID > 0x4BB83D07 )
          {
            switch ( mUID )
            {
              case 0x4E2E4E98u:
                return 7i64;
              case 0x5216673Fu:
                return 55i64;
              case 0x55FA1C83u:
                return 91i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x4BB83D07u:
                return 10i64;
              case 0x467CB131u:
                return 36i64;
              case 0x46FB1BDEu:
                return 11i64;
              case 0x487BACC6u:
                return 123i64;
              case 0x491008DEu:
                return 98i64;
            }
          }
        }
      }
    }
    else
    {
      if ( mUID == 1154528762 )
        return 137i64;
      if ( mUID > 0x2E274CD7 )
      {
        if ( mUID > 0x3A4F25B8 )
        {
          if ( mUID > 0x3EBC4E1B )
          {
            switch ( mUID )
            {
              case 0x423A0669u:
                return 12i64;
              case 0x42DAC217u:
                return 127i64;
              case 0x43AA4772u:
                return 39i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x3EBC4E1Bu:
                return 67i64;
              case 0x3D60854Eu:
                return 94i64;
              case 0x3D82D296u:
                return 32i64;
              case 0x3E8E380Fu:
                return 30i64;
            }
          }
        }
        else
        {
          if ( mUID == 978265528 )
            return 29i64;
          if ( mUID > 0x36FCD1D2 )
          {
            switch ( mUID )
            {
              case 0x370C0361u:
                return 28i64;
              case 0x372CF26Bu:
                return 117i64;
              case 0x394AAD1Du:
                return 66i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x36FCD1D2u:
                return 120i64;
              case 0x2F168123u:
                return 105i64;
              case 0x31518817u:
                return 65i64;
              case 0x32709C10u:
                return 43i64;
            }
          }
        }
      }
      else
      {
        if ( mUID == 774327511 )
          return 35i64;
        if ( mUID > 0x19D5CDE5 )
        {
          if ( mUID > 0x21E7A173 )
          {
            switch ( mUID )
            {
              case 0x2794EF40u:
                return 89i64;
              case 0x2836659Cu:
                return 121i64;
              case 0x2A6D9EBEu:
                return 125i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x21E7A173u:
                return 113i64;
              case 0x1A403B6Cu:
                return 126i64;
              case 0x1C93761Au:
                return 95i64;
              case 0x1F1BD623u:
                return 97i64;
            }
          }
        }
        else
        {
          if ( mUID == 433442277 )
            return 63i64;
          if ( mUID > 0x1022948B )
          {
            switch ( mUID )
            {
              case 0x11CF5675u:
                return 21i64;
              case 0x12F561AFu:
                return 60i64;
              case 0x13CEC003u:
                return 64i64;
            }
          }
          else
          {
            switch ( mUID )
            {
              case 0x1022948Bu:
                return 102i64;
              case 0x2E0E39Du:
                return 46i64;
              case 0x33ECBBBu:
                return 107i64;
              case 0x55AC58Cu:
                return 56i64;
              case 0x7F6E4BEu:
                return 103i64;
            }
          }
        }
      }
    }
    return 139i64;
  }
  if ( mUID <= 0xC04D3273 )
  {
    if ( mUID == -1068682637 )
      return 58i64;
    if ( mUID > 0x9EDC4646 )
    {
      if ( mUID > 0xAF5330D0 )
      {
        if ( mUID > 0xB8BDA89D )
        {
          switch ( mUID )
          {
            case 0xBBA48FAF:
              return 129i64;
            case 0xBC83EEF1:
              return 96i64;
            case 0xBE1564DA:
              return 111i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0xB8BDA89D:
              return 135i64;
            case 0xB07B310B:
              return 62i64;
            case 0xB18054E3:
              return 75i64;
            case 0xB4B6B007:
              return 124i64;
            case 0xB5858AD5:
              return 118i64;
          }
        }
      }
      else
      {
        if ( mUID == -1353502512 )
          return 133i64;
        if ( mUID > 0xA760CF19 )
        {
          switch ( mUID )
          {
            case 0xA81937E3:
              return 122i64;
            case 0xAB922D67:
              return 132i64;
            case 0xABDFA54F:
              return 106i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0xA760CF19:
              return 115i64;
            case 0xA0B85B62:
              return 78i64;
            case 0xA1FA3D55:
              return 0i64;
            case 0xA2101609:
              return 134i64;
            case 0xA55322EC:
              return 92i64;
          }
        }
      }
    }
    else
    {
      if ( mUID == -1629731258 )
        return 88i64;
      if ( mUID > 0x8E580C5F )
      {
        if ( mUID > 0x97B8D543 )
        {
          switch ( mUID )
          {
            case 0x997644C6:
              return 100i64;
            case 0x9C9875CD:
              return 114i64;
            case 0x9DB75971:
              return 99i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x97B8D543:
              return 38i64;
            case 0x8EBBE682:
              return 72i64;
            case 0x92C601EE:
              return 128i64;
            case 0x93F9C729:
              return 5i64;
            case 0x9435621F:
              return 101i64;
          }
        }
      }
      else
      {
        if ( mUID == -1906832289 )
          return 84i64;
        if ( mUID > 0x87E96C6E )
        {
          switch ( mUID )
          {
            case 0x89761C60:
              return 131i64;
            case 0x8AA51153:
              return 37i64;
            case 0x8B9BD981:
              return 13i64;
            case 0x8D12CC4B:
              return 119i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x87E96C6E:
              return 74i64;
            case 0x7DC82D12u:
              return 45i64;
            case 0x831B2A86:
              return 83i64;
            case 0x83512B7F:
              return 26i64;
            case 0x87DA3731:
              return 82i64;
          }
        }
      }
    }
    return 139i64;
  }
  if ( mUID <= 0xD87294B5 )
  {
    if ( mUID == -663579467 )
      return 77i64;
    if ( mUID > 0xCD140126 )
    {
      if ( mUID > 0xD21429D3 )
      {
        switch ( mUID )
        {
          case 0xD5A3C5AA:
            return 4i64;
          case 0xD5E2CAD5:
            return 69i64;
          case 0xD7ECE162:
            return 48i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xD21429D3:
            return 70i64;
          case 0xCEF0B49B:
            return 93i64;
          case 0xCF11B354:
            return 53i64;
          case 0xCF5CE03F:
            return 20i64;
          case 0xD01A0264:
            return 49i64;
        }
      }
    }
    else
    {
      if ( mUID == -854327002 )
        return 79i64;
      if ( mUID > 0xC4963A48 )
      {
        switch ( mUID )
        {
          case 0xC60796CD:
            return 1i64;
          case 0xC9D51C91:
            return 80i64;
          case 0xCBD0AEE3:
            return 54i64;
          case 0xCC65CDAC:
            return 34i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xC4963A48:
            return 81i64;
          case 0xC20AB555:
            return 87i64;
          case 0xC252958D:
            return 52i64;
          case 0xC2A33E31:
            return 57i64;
          case 0xC33005A1:
            return 76i64;
        }
      }
    }
    return 139i64;
  }
  if ( mUID <= 0xE8833595 )
  {
    if ( mUID == -394054251 )
      return 9i64;
    if ( mUID > 0xE251143A )
    {
      switch ( mUID )
      {
        case 0xE2E3A218:
          return 112i64;
        case 0xE4358A12:
          return 41i64;
        case 0xE4720C95:
          return 61i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0xE251143A:
          return 3i64;
        case 0xDDF9EFDF:
          return 68i64;
        case 0xDF076753:
          return 6i64;
        case 0xDFF7C468:
          return 47i64;
        case 0xE1045130:
          return 59i64;
      }
    }
    return 139i64;
  }
  if ( mUID <= 0xF8E1F4C6 )
  {
    switch ( mUID )
    {
      case 0xF8E1F4C6:
        return 2i64;
      case 0xEC28560D:
        return 138i64;
      case 0xF120FC1A:
        return 109i64;
      case 0xF45F09A2:
        return 14i64;
      case 0xF48DF448:
        return 85i64;
    }
    return 139i64;
  }
  if ( mUID == -115593349 )
    return 15i64;
  if ( mUID == -55827904 )
    return 86i64;
  if ( mUID != -35835188 )
    return 139i64;
  return 16i64;
}      return 59i64;
      }
    }
    return 139i64;
  }
  if ( mUID <= 0xF8E1F4C6 )
  {
    s

// File Line: 266
// RVA: 0x4A37F0
__int64 __fastcall UFG::GameStat::GetInt32RangedStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x6B369BA6 )
  {
    switch ( mUID )
    {
      case 0x6B369BA6u:
        return 5i64;
      case 0x4C856CAu:
        return 0i64;
      case 0x3E3CED8Bu:
        return 2i64;
      case 0x43581EC2u:
        return 6i64;
    }
    return 7i64;
  }
  if ( mUID == 1855574845 )
    return 4i64;
  if ( mUID == -1954782142 )
    return 1i64;
  if ( mUID != -1255360625 )
    return 7i64;
  return 3i64;
}

// File Line: 280
// RVA: 0x4A2A20
_BOOL8 __fastcall UFG::GameStat::GetFloatRangedStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  return name->mUID != 1831296723;
}

// File Line: 294
// RVA: 0x4A6AB0
__int64 __fastcall UFG::GameStat::GetStringStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x697CF8E1 )
  {
    if ( mUID == 1769797857 )
      return 2i64;
    if ( mUID > 0x36810BF3 )
    {
      switch ( mUID )
      {
        case 0x4C19F50Fu:
          return 8i64;
        case 0x60FEC38Fu:
          return 0i64;
        case 0x643FDE38u:
          return 1i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0x36810BF3u:
          return 23i64;
        case 0x62DD969u:
          return 24i64;
        case 0x13696963u:
          return 11i64;
        case 0x2F86734Bu:
          return 7i64;
        case 0x327C6FB1u:
          return 22i64;
      }
    }
    return 25i64;
  }
  if ( mUID <= 0xD3AF4B4F )
  {
    if ( mUID == -743486641 )
      return 15i64;
    if ( mUID > 0xABBAF1FE )
    {
      switch ( mUID )
      {
        case 0xBC755C0E:
          return 14i64;
        case 0xCC3ACA29:
          return 20i64;
        case 0xCF06DA85:
          return 16i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0xABBAF1FE:
          return 18i64;
        case 0x75D099EBu:
          return 13i64;
        case 0x8495D342:
          return 19i64;
        case 0x85AFEDC1:
          return 21i64;
        case 0x958197CB:
          return 6i64;
      }
    }
    return 25i64;
  }
  if ( mUID <= 0xE9FEE60B )
  {
    switch ( mUID )
    {
      case 0xE9FEE60B:
        return 4i64;
      case 0xDACCAC86:
        return 12i64;
      case 0xDC1636F3:
        return 9i64;
      case 0xE4BDC0D2:
        return 5i64;
    }
    return 25i64;
  }
  if ( mUID == -314573892 )
    return 3i64;
  if ( mUID == -218355561 )
    return 17i64;
  if ( mUID != -77989936 )
    return 25i64;
  return 10i64;
}

// File Line: 322
// RVA: 0x4A47C0
__int64 __fastcall UFG::GameStat::GetMapBoolStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x7C910D9E )
  {
    if ( mUID == 2089880990 )
      return 28i64;
    if ( mUID > 0x3CD97790 )
    {
      if ( mUID > 0x542C0CAD )
      {
        if ( mUID > 0x6DD37AD5 )
        {
          switch ( mUID )
          {
            case 0x70238BEAu:
              return 18i64;
            case 0x71597DD7u:
              return 83i64;
            case 0x723CFB71u:
              return 33i64;
            case 0x79880A0Au:
              return 77i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x6DD37AD5u:
              return 10i64;
            case 0x64992F59u:
              return 31i64;
            case 0x665FC5D5u:
              return 61i64;
            case 0x68AAE020u:
              return 70i64;
            case 0x6937DD24u:
              return 76i64;
          }
        }
      }
      else
      {
        if ( mUID == 1412172973 )
          return 53i64;
        if ( mUID > 0x4A2575D3 )
        {
          switch ( mUID )
          {
            case 0x4A846F2Fu:
              return 7i64;
            case 0x4D8DC2FAu:
              return 87i64;
            case 0x5133AFCDu:
              return 24i64;
            case 0x53CA92FFu:
              return 88i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x4A2575D3u:
              return 63i64;
            case 0x3FF5C9A8u:
              return 55i64;
            case 0x43E26DCFu:
              return 11i64;
            case 0x440FF994u:
              return 85i64;
            case 0x48786F7Bu:
              return 16i64;
            case 0x494CDF4Du:
              return 86i64;
          }
        }
      }
    }
    else
    {
      if ( mUID == 1020884880 )
        return 26i64;
      if ( mUID > 0x24725572 )
      {
        if ( mUID > 0x35C325A2 )
        {
          switch ( mUID )
          {
            case 0x361F67F0u:
              return 66i64;
            case 0x3880037Bu:
              return 50i64;
            case 0x3B884960u:
              return 21i64;
            case 0x3C411ECCu:
              return 49i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x35C325A2u:
              return 47i64;
            case 0x247526BDu:
              return 80i64;
            case 0x26C7537Eu:
              return 43i64;
            case 0x2B8475A7u:
              return 46i64;
            case 0x2F456810u:
              return 45i64;
            case 0x31023815u:
              return 48i64;
          }
        }
      }
      else
      {
        if ( mUID == 611472754 )
          return 62i64;
        if ( mUID > 0x8C19049 )
        {
          switch ( mUID )
          {
            case 0x117BD5C3u:
              return 30i64;
            case 0x1BC1282Fu:
              return 73i64;
            case 0x1E364071u:
              return 19i64;
            case 0x22064EC9u:
              return 44i64;
          }
        }
        else
        {
          switch ( mUID )
          {
            case 0x8C19049u:
              return 17i64;
            case 0xCFBEC6u:
              return 51i64;
            case 0x27E2928u:
              return 79i64;
            case 0x40EA371u:
              return 52i64;
            case 0x4F8F7DAu:
              return 15i64;
            case 0x611C3E7u:
              return 6i64;
          }
        }
      }
    }
    return 93i64;
  }
  if ( mUID <= 0xCDBC4485 )
  {
    if ( mUID == -843299707 )
      return 54i64;
    if ( mUID > 0xA8DBC3C3 )
    {
      if ( mUID > 0xB8E0E139 )
      {
        switch ( mUID )
        {
          case 0xC1A133C2:
            return 67i64;
          case 0xC4CDAAA6:
            return 23i64;
          case 0xC6727847:
            return 72i64;
          case 0xC8D8E5EA:
            return 64i64;
          case 0xCA15B992:
            return 32i64;
        }
      }
      else
      {
        if ( mUID == -1193221831 )
          return 25i64;
        if ( mUID > 0xB3E1E3C9 )
        {
          if ( mUID == -1223333173 )
            return 84i64;
          if ( mUID == -1203949030 )
            return 5i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0xB3E1E3C9:
              return 58i64;
            case 0xA914C2A6:
              return 59i64;
            case 0xAAD26ED2:
              return 13i64;
            case 0xAC6C3CC2:
              return 69i64;
          }
        }
      }
    }
    else
    {
      if ( mUID == -1461992509 )
        return 9i64;
      if ( mUID > 0x9542436A )
      {
        switch ( mUID )
        {
          case 0x96F94396:
            return 89i64;
          case 0x9A968189:
            return 12i64;
          case 0x9BBA654F:
            return 90i64;
          case 0x9F7B78F8:
            return 91i64;
          case 0xA891990E:
            return 82i64;
        }
      }
      else
      {
        if ( mUID == -1790819478 )
          return 29i64;
        if ( mUID > 0x8E3D9278 )
        {
          if ( mUID == -1868564411 )
            return 20i64;
          if ( mUID == -1849709840 )
            return 2i64;
        }
        else
        {
          switch ( mUID )
          {
            case 0x8E3D9278:
              return 4i64;
            case 0x7D9AB22Cu:
              return 81i64;
            case 0x813C28FD:
              return 92i64;
            case 0x87B2FEB2:
              return 3i64;
          }
        }
      }
    }
    return 93i64;
  }
  if ( mUID <= 0xE7DAE47E )
  {
    if ( mUID == -405085058 )
      return 37i64;
    if ( mUID > 0xD2F71181 )
    {
      switch ( mUID )
      {
        case 0xD61762AD:
          return 42i64;
        case 0xD9A17E8B:
          return 1i64;
        case 0xE0604027:
          return 71i64;
        case 0xE31BF9C9:
          return 38i64;
        case 0xE37F9777:
          return 74i64;
      }
    }
    else
    {
      if ( mUID == -755560063 )
        return 56i64;
      if ( mUID > 0xD15D2F54 )
      {
        if ( mUID == -774204015 )
          return 75i64;
        if ( mUID == -757694694 )
          return 41i64;
      }
      else
      {
        switch ( mUID )
        {
          case 0xD15D2F54:
            return 14i64;
          case 0xCE3B48E3:
            return 68i64;
          case 0xCE55CDE1:
            return 65i64;
          case 0xCEB3154E:
            return 57i64;
        }
      }
    }
    return 93i64;
  }
  if ( mUID <= 0xF0E668E7 )
  {
    switch ( mUID )
    {
      case 0xF0E668E7:
        return 78i64;
      case 0xE96F08F5:
        return 27i64;
      case 0xEA99C2A7:
        return 40i64;
      case 0xEC484682:
        return 8i64;
      case 0xEE58DF10:
        return 39i64;
      case 0xF01F8F15:
        return 34i64;
    }
    return 93i64;
  }
  switch ( mUID )
  {
    case 0xF83ECD6B:
      return 60i64;
    case 0xF8447E4C:
      return 0i64;
    case 0xF99DB47B:
      return 36i64;
    case 0xFD5CA9CC:
      return 35i64;
  }
  if ( mUID != -8301145 )
    return 93i64;
  return 22i64;
}

// File Line: 336
// RVA: 0x4A4E40
__int64 __fastcall UFG::GameStat::GetMapInt32StatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x7DC907CE )
  {
    if ( mUID == 2110326734 )
      return 20i64;
    if ( mUID > 0x249E325F )
    {
      if ( mUID > 0x5A15AD4E )
      {
        switch ( mUID )
        {
          case 0x65EA5F2Bu:
            return 22i64;
          case 0x728E1CC0u:
            return 1i64;
          case 0x7C2448A5u:
            return 2i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x5A15AD4Eu:
            return 14i64;
          case 0x26FE70D7u:
            return 27i64;
          case 0x298ABDDBu:
            return 10i64;
          case 0x2B4E5BAAu:
            return 33i64;
          case 0x32731651u:
            return 32i64;
        }
      }
    }
    else
    {
      if ( mUID == 614347359 )
        return 8i64;
      if ( mUID > 0xAF0751D )
      {
        switch ( mUID )
        {
          case 0x1BB8FA05u:
            return 23i64;
          case 0x1FEA8342u:
            return 18i64;
          case 0x204EC089u:
            return 4i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0xAF0751Du:
            return 36i64;
          case 0x225393Bu:
            return 24i64;
          case 0x781C5CAu:
            return 0i64;
          case 0x82A9586u:
            return 38i64;
          case 0x84FC6F5u:
            return 25i64;
        }
      }
    }
    return 47i64;
  }
  if ( mUID <= 0xC1271821 )
  {
    if ( mUID == -1054402527 )
      return 26i64;
    if ( mUID > 0x9F328BA9 )
    {
      if ( mUID > 0xB54277B1 )
      {
        if ( mUID == -1205681139 )
          return 13i64;
        if ( mUID == -1056663930 )
          return 43i64;
      }
      else
      {
        switch ( mUID )
        {
          case 0xB54277B1:
            return 34i64;
          case 0xA183FE8B:
            return 21i64;
          case 0xA8E5186F:
            return 16i64;
          case 0xB27A2FD5:
            return 15i64;
        }
      }
    }
    else
    {
      if ( mUID == -1624077399 )
        return 41i64;
      if ( mUID > 0x96B0B0C7 )
      {
        switch ( mUID )
        {
          case 0x9BF3961E:
            return 40i64;
          case 0x9C6454D0:
            return 35i64;
          case 0x9F2DB8C0:
            return 19i64;
        }
      }
      else
      {
        switch ( mUID )
        {
          case 0x96B0B0C7:
            return 39i64;
          case 0x7DCC5032u:
            return 6i64;
          case 0x8175DBAC:
            return 42i64;
          case 0x93910E97:
            return 17i64;
        }
      }
    }
    return 47i64;
  }
  if ( mUID <= 0xD6C1FDED )
  {
    if ( mUID == -691929619 )
      return 46i64;
    if ( mUID > 0xC886ADE8 )
    {
      switch ( mUID )
      {
        case 0xCA08E718:
          return 30i64;
        case 0xCA42CD99:
          return 12i64;
        case 0xCC47B05F:
          return 44i64;
      }
    }
    else
    {
      switch ( mUID )
      {
        case 0xC886ADE8:
          return 45i64;
        case 0xC413C487:
          return 11i64;
        case 0xC4961D2D:
          return 29i64;
        case 0xC671FEE4:
          return 9i64;
      }
    }
    return 47i64;
  }
  if ( mUID <= 0xDEA94502 )
  {
    switch ( mUID )
    {
      case 0xDEA94502:
        return 7i64;
      case 0xD92A0B17:
        return 5i64;
      case 0xDB24FEF1:
        return 3i64;
      case 0xDB6BCD5E:
        return 31i64;
    }
    return 47i64;
  }
  if ( mUID == -190007928 )
    return 28i64;
  if ( mUID != -3850668 )
    return 47i64;
  return 37i64;
}

// File Line: 364
// RVA: 0x4A4D40
__int64 __fastcall UFG::GameStat::GetMapFloatStatEnum(UFG::qSymbol *name, bool warnIfNotFound)
{
  unsigned int mUID; // eax

  mUID = name->mUID;
  if ( name->mUID <= 0x7AA891BD )
  {
    switch ( mUID )
    {
      case 0x7AA891BDu:
        return 1i64;
      case 0x5640EC66u:
        return 4i64;
      case 0x685D908Du:
        return 17i64;
      case 0x72DBDD3Fu:
        return 15i64;
      case 0x761AC088u:
        return 16i64;
    }
    return 18i64;
  }
  if ( mUID <= 0x9C78AFB8 )
  {
    if ( mUID == -1669812296 )
      return 11i64;
    if ( mUID > 0x913B8961 )
    {
      if ( mUID == -1732660721 )
        return 12i64;
      if ( mUID == -1682467663 )
        return 9i64;
    }
    else
    {
      switch ( mUID )
      {
        case 0x913B8961:
          return 10i64;
        case 0x7F98FBE6u:
          return 14i64;
        case 0x860ABF2C:
          return 2i64;
        case 0x86FEE20A:
          return 13i64;
      }
    }
    return 18i64;
  }
  if ( mUID <= 0xED63DE37 )
  {
    switch ( mUID )
    {
      case 0xED63DE37:
        return 7i64;
      case 0xBB7DA1A0:
        return 6i64;
      case 0xD4BD9906:
        return 5i64;
      case 0xE4492DA6:
        return 3i64;
    }
    return 18i64;
  }
  if ( mUID == -195128372 )
    return 8i64;
  if ( mUID != -137383293 )
    return 18i64;
  return 0i64;
}

