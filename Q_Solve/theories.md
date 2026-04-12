## Q1. Define the following terms in your own words: Data, Entity, Attributes, Records, and Data structure 

**Data**: Data is a collection of facts, figures, or information that can be processed or analyzed. It can be in various forms such as numbers, text, images, etc.

**Entity**: An entity is a real-world object or concept that can be distinctly identified. It can be a person, place, thing, or event that has attributes and can be represented in a database. 

**Attributes**: Attributes are the properties or characteristics of an entity. They provide more information about the entity and help to describe it. For example, for a "Student" entity, attributes could include "Name", "Age", "Grade", etc.

**Records**: Records are a collection of related attributes that describe a single entity. Example: A record for a student might include the attributes "Name: John Doe", "Age: 20", "Grade: A".

**Data structure**: A data structure is a way of organizing and storing data in a computer so that it can be accessed and modified efficiently. Examples of data structures include arrays, linked lists, stacks, queues, trees, and graphs. Each data structure has its own advantages and disadvantages depending on the use case.

## Q2. Explain algorithm complexity, a time-space tradeoff


### **Algorithm Complexity**

Algorithm complexity measures how efficient an algorithm is in terms of:

1. **Time Complexity**: How long an algorithm takes to run as a function of the input size (n)

Example:
- Linear Search → $𝑂(𝑛)$
- Binary Search → $𝑂(log 𝑛)$

2. **Space Complexity 💾**: How much memory an algorithm uses

Example:
- Storing extra arrays increases space usage
- Using fewer variables reduces space

### **Time-Space Tradeoff**

The time-space tradeoff is a concept in computer science where you can often reduce the time complexity of an algorithm by using more space, or reduce the space complexity by allowing the algorithm to take more time.

Example:
- Hash Table Search: O(1) time complexity but uses more space

So, here is the tradeoff, where you use more space to achieve faster results, or use less space but accept slower performance.

