/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.rows;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Wap
 */
public final class MemberRow implements Extractable{
    private String name;
    private int age;
    private String gender;
    private String position;
    private String occupation;
    private String personality;
    private String skills;
    private String race;
    private int mass;
    private String status;

    /**
     *
     */
    public MemberRow() {
        setName(null);
        setAge(-1);
        setGender(null);
        setPosition(null);
        setOccupation(null);
        setPersonality(null);
        setSkills(null);
        setRace(null);
        setMass(-1);
        setStatus(null);
    }
    
    /**
     *
     * @param name
     * @param age
     * @param gender
     * @param position
     * @param occupation
     * @param personality
     * @param skills
     * @param race
     * @param mass
     * @param status
     */
    public MemberRow(String name, int age, String gender, String position, String occupation, String personality, String skills, String race, int mass, String status) {
        setName(name);
        setAge(age);
        setGender(gender);
        setPosition(position);
        setOccupation(occupation);
        setPersonality(personality);
        setSkills(skills);
        setRace(race);
        setMass(mass);
        setStatus(status);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new MemberRow(resultSet.getString(1), resultSet.getInt(2), resultSet.getString(3), resultSet.getString(4), resultSet.getString(5), resultSet.getString(6), resultSet.getString(7), resultSet.getString(8), resultSet.getInt(9), resultSet.getString(10));
    }

    /**
     *
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     *
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     *
     * @return
     */
    public int getAge() {
        return age;
    }

    /**
     *
     * @param age
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     *
     * @return
     */
    public String getGender() {
        return gender;
    }

    /**
     *
     * @param gender
     */
    public void setGender(String gender) {
        this.gender = gender;
    }

    /**
     *
     * @return
     */
    public String getPosition() {
        return position;
    }

    /**
     *
     * @param position
     */
    public void setPosition(String position) {
        this.position = position;
    }

    /**
     *
     * @return
     */
    public String getOccupation() {
        return occupation;
    }

    /**
     *
     * @param occupation
     */
    public void setOccupation(String occupation) {
        this.occupation = occupation;
    }

    /**
     *
     * @return
     */
    public String getPersonality() {
        return personality;
    }

    /**
     *
     * @param personality
     */
    public void setPersonality(String personality) {
        this.personality = personality;
    }

    /**
     *
     * @return
     */
    public String getSkills() {
        return skills;
    }

    /**
     *
     * @param skills
     */
    public void setSkills(String skills) {
        this.skills = skills;
    }

    /**
     *
     * @return
     */
    public String getRace() {
        return race;
    }

    /**
     *
     * @param race
     */
    public void setRace(String race) {
        this.race = race;
    }

    /**
     *
     * @return
     */
    public int getMass() {
        return mass;
    }

    /**
     *
     * @param mass
     */
    public void setMass(int mass) {
        this.mass = mass;
    }

    /**
     *
     * @return
     */
    public String getStatus() {
        return status;
    }

    /**
     *
     * @param status
     */
    public void setStatus(String status) {
        this.status = status;
    }
}
