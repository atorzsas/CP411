# CP411 Project: Final Project Proposal

Author(s): Jacob Reil - 210514020, Alexander Torzsas - 210233050

Professor: HBF

Date: 2023-11-28

## 1 Introduction

Our Interactive 3D City Builder is a computer graphics application that allows users to design and build their own virtual city in a 3D environment. The project aims to provide an immersive experience where users can express their creativity in urban planning and architecture. By offering a wide range of tools and elements like buildings, roads, and natural landscapes, the application serves as a sandbox for experimenting with city design concepts.

**Rationales:**

- **Educational Value:** Teaches basics of city layout and sustainable planning.
- **Technical Showcase:** Implements advanced 3D modeling and rendering using OpenGL.
- **User Engagement:** Encourages creative problem-solving and design thinking.

## 2 Problem-solving and algorithms

The primary computing challenge in the Interactive 3D City Builder is the efficient and intuitive manipulation of 3D objects within a complex virtual environment. This involves several key aspects:

- **3D Object Picking:** Accurate selection and interaction with 3D objects using a 2D mouse.
- **Responsive Object Manipulation:** Seamless movement, rotation, and placement of 3D objects.
- **Performance Optimization:** Smooth handling of a large number of 3D objects.

**Possible Solutions and Algorithms:**

- **Ray Picking for Object Selection:**
    - **Ray Casting:** Translates 2D mouse coordinates to a 3D ray.
    - **Intersection Tests:** Checks ray intersection with 3D object boundaries.
    - **Selection Logic:** Identifies the nearest object intersecting with the ray.

- **Object Manipulation Techniques:**
    - **Translation and Rotation:** Based on user input.
    - **Grid Snapping:** Aligns objects to a predefined grid for precise placement.
    - **Constraint-based Manipulation:** Prevents unrealistic placements.

- **User Interface Enhancements:**
    - **Direct Manipulation Interface:** Intuitive GUI for object handling.
    - **Visual Feedback:** Highlights selected objects.
    - **Contextual Tools:** Menus and tooltips for information and control.

## 3 Design consideration

**System Design Overview**

The Interactive 3D City Builder is designed to be a robust, user-friendly application that allows users to create, manipulate, and explore 3D urban environments. The system architecture is based on the Model-View-Controller (MVC) pattern, which separates the application into three interconnected components. This design pattern facilitates ease of development, maintenance, and scalability.

**MVC Architecture**

- **Model:** Manages data and logic, containing 3D representations (buildings, roads, trees) and interaction logic. It also includes a scene graph for organizing 3D objects, an optional physics engine for realistic interactions, and data persistence for saving/loading designs.
- **View:** Responsible for rendering model data and UI, using OpenGL for 3D city rendering. Includes a GUI layer for user interaction and camera control for navigating the 3D environment.
- **Controller:** Interfaces between Model and View, handling user input, object manipulation, and UI interaction logic.

**Additional Design Considerations**

- **Modularity:** Ensure each component (Model, View, Controller) is modular to facilitate independent development and testing.
- **Performance Optimization:** Incorporate techniques like Level of Detail, Frustum Culling, and efficient data structures for optimal performance.
- **User Experience (UX):** Design the GUI to be intuitive and responsive, focusing on ease of use for novice and experienced users.

The application ensures a well-structured, maintainable, and scalable foundation for a sophisticated and user-friendly experience by adhering to MVC.

## 4 Milestones & schedule

List of tasks/milestones/check points of your project with time schedule. For group project, it needs to provide the roles and tasks of each member.

| Task ID | Description               | Due date    | Lead  |
|---------|---------------------------|-------------|-------|
| 1       | Project research & team up| Nov. 20, 2023 | Jacob |
| 2       | Project proposal          | Nov. 28, 2023 | Alex  |
| 3       | Project checkpoint        | Dec 1st, 2023 | Jacob |
| 4       | Project checkpoint        | Dec 3rd, 2023 | Alex  |
| 5       | Project demonstration     | Dec. 5, 2023 | Jacob |
| 6       | Project Submission        | Dec. 5, 2023 | Alex  |
