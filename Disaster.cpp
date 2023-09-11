#include "Disaster.h"

// Default constructor
Disaster::Disaster() : m_name(""), m_damagePercent(0) {}

// Parameterized constructor
Disaster::Disaster(std::string name, int damagePercent)
    : m_name(name)
    , m_damagePercent(damagePercent) {}

// Destructor
Disaster::~Disaster() 
{
}
