#include "include/BlockHeader/BlockStorage.h"

using namespace std;

BlockStorage::BlockStorage(shared_ptr<BaseBlock> baseBlock, int quantity, int typeStorage)
    :Block(baseBlock, true, 1)
    ,m_storageType(typeStorage)
    ,m_quantity(quantity)
    ,m_capacity(baseBlock->getConfig()->m_storageDefaultCapacity)
{
}

void BlockStorage::setQuantity(int quantity)
{
    m_quantity = quantity;
}
int BlockStorage::getQuantity()
{
    return m_quantity;
}
bool BlockStorage::dimQuantity(int quantity)
{
    m_quantity = max(m_quantity - quantity,0);
    return false;
}
void BlockStorage::addQuantity(int quantity)
{
    m_quantity = m_quantity + quantity;
}
int BlockStorage::getStorageType()
{
    return m_storageType;
}

int BlockStorage::getCapacity()
{
    return m_capacity;
}

bool BlockStorage::isEmpty()
{
    return (m_quantity == 0);
}

std::string BlockStorage::getInfo()
{
    std::stringstream sstm;
    sstm << Block::getInfo() << "    Resource Type : " << getStorageType() << "   Quantity : " << getQuantity();
    return sstm.str();
}

void BlockStorage::update(int i)
{
    if (i%100 == 0)
        dimQuantity(m_quantity/100);
}
