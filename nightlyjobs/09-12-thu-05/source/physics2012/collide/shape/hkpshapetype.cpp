// File Line: 13
// RVA: 0xD19AC0
void __fastcall hkpRegisterAlternateShapeTypes(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher *v1; // rbx

  v1 = dis;
  hkpCollisionDispatcher::registerAlternateShapeType(dis, 0, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRIANGLE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, BOX, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CAPSULE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CYLINDER, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_VERTICES, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_TRANSLATE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_TRANSFORM, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX_PIECE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRIANGLE_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, LIST, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, EXTENDED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, COMPRESSED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, MOPP, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, STATIC_COMPOUND, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, BV_COMPRESSED_MESH, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, CONVEX, SPHERE_REP);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, PLANE, HEIGHT_FIELD);
  hkpCollisionDispatcher::registerAlternateShapeType(v1, SAMPLED_HEIGHT_FIELD, HEIGHT_FIELD);
}

// File Line: 45
// RVA: 0xD198D0
const char *__fastcall hkGetShapeTypeName(hkcdShapeType::ShapeTypeEnum type)
{
  const char *result; // rax

  switch ( type + 1 )
  {
    case 0u:
      result = "hkcdShapeType::ALL_SHAPE_TYPES";
      break;
    case 1u:
      result = "hkcdShapeType::SPHERE";
      break;
    case 2u:
      result = "hkcdShapeType::CYLINDER";
      break;
    case 3u:
      result = "hkcdShapeType::TRIANGLE";
      break;
    case 4u:
      result = "hkcdShapeType::BOX";
      break;
    case 5u:
      result = "hkcdShapeType::CAPSULE";
      break;
    case 6u:
      result = "hkcdShapeType::CONVEX_VERTICES";
      break;
    case 7u:
      result = "hkcdShapeType::TRI_SAMPLED_HEIGHT_FIELD_COLLECTION";
      break;
    case 8u:
      result = "hkcdShapeType::TRI_SAMPLED_HEIGHT_FIELD_BV_TREE";
      break;
    case 9u:
      result = "hkcdShapeType::LIST";
      break;
    case 0xAu:
      result = "hkcdShapeType::MOPP";
      break;
    case 0xBu:
      result = "hkcdShapeType::CONVEX_TRANSLATE";
      break;
    case 0xCu:
      result = "hkcdShapeType::CONVEX_TRANSFORM";
      break;
    case 0xDu:
      result = "hkcdShapeType::SAMPLED_HEIGHT_FIELD";
      break;
    case 0xEu:
      result = "hkcdShapeType::EXTENDED_MESH";
      break;
    case 0xFu:
      result = "hkcdShapeType::TRANSFORM";
      break;
    case 0x10u:
      result = "hkcdShapeType::COMPRESSED_MESH";
      break;
    case 0x11u:
      result = "hkcdShapeType::STATIC_COMPOUND";
      break;
    case 0x12u:
      result = "hkcdShapeType::BV_COMPRESSED_MESH";
      break;
    case 0x13u:
      result = "hkcdShapeType::COLLECTION";
      break;
    case 0x14u:
      result = "hkcdShapeType::USER0";
      break;
    case 0x15u:
      result = "hkcdShapeType::USER1";
      break;
    case 0x16u:
      result = "hkcdShapeType::USER2";
      break;
    case 0x17u:
      result = "hkcdShapeType::BV_TREE";
      break;
    case 0x18u:
      result = "hkcdShapeType::CONVEX";
      break;
    case 0x19u:
      result = "hkcdShapeType::CONVEX_PIECE";
      break;
    case 0x1Au:
      result = "hkcdShapeType::MULTI_SPHERE";
      break;
    case 0x1Bu:
      result = "hkcdShapeType::CONVEX_LIST";
      break;
    case 0x1Cu:
      result = "hkcdShapeType::TRIANGLE_COLLECTION";
      break;
    case 0x1Du:
      result = "hkcdShapeType::HEIGHT_FIELD";
      break;
    case 0x1Eu:
      result = "hkcdShapeType::SPHERE_REP";
      break;
    case 0x1Fu:
      result = "hkcdShapeType::BV";
      break;
    case 0x20u:
      result = "hkcdShapeType::PLANE";
      break;
    case 0x21u:
      result = "hkcdShapeType::PHANTOM_CALLBACK";
      break;
    case 0x22u:
      result = "hkcdShapeType::MULTI_RAY";
      break;
    case 0x23u:
      result = "hkcdShapeType::INVALID";
      break;
    case 0x24u:
      result = "hkcdShapeType::MAX_PPU_SHAPE_TYPE";
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

