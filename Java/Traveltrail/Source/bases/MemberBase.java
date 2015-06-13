/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.bases;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import traveltrail.interfaces.Extractable;
import traveltrail.interfaces.Preparable;

/**
 *
 * @author Anomaly
 */
public final class MemberBase implements Extractable, Preparable {
    private String name;
    private int age;
    private String gender;
    private ArrayList<String> positions;
    private ArrayList<String> occupations;
    private String personality;
    private String skills;
    private String race;
    private int mass;
    
    /**
     * Default Constructor
     */
    public MemberBase() {
    }
    
    public MemberBase(MemberBase other) {
        setName(other.getName());
        setGender(other.getGender());
        setPosition(other.getPositions());
        setOccupation(other.getOccupations());
        setPersonality(other.getPersonality());
        setSkills(other.getSkills());
        setRace(other.getRace());
        setAge(other.getAge());
        setMass(other.getMass());
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
     */
    public MemberBase(String name, String gender, String position, String occupation, String personality, String skills, String race, int age, int mass) {
        setName(name);
        setGender(gender);
        setPositions(position);
        setOccupations(occupation);
        setPersonality(personality);
        setSkills(skills);
        setRace(race);
        setAge(age);
        setMass(mass);
    }
    
    /**
     * 
     * @param resultSet
     * @return
     * @throws SQLException 
     */
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException {
        int index = startingIndex;
        startingIndex += 9;
        return new MemberBase(resultSet.getString(index), 
                              resultSet.getString(++index),
                              resultSet.getString(++index),
                              resultSet.getString(++index),
                              resultSet.getString(++index),
                              resultSet.getString(++index),
                              resultSet.getString(++index),
                              resultSet.getInt(++index),
                              resultSet.getInt(++index));
    }
    
    /**
     * 
     * @param preparedStatement
     * @throws SQLException 
     */    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement, Integer startingIndex) throws SQLException {
        int index = startingIndex;
        startingIndex += 9;
        preparedStatement.setString(index, getName());
        preparedStatement.setString(++index, getGender());
        preparedStatement.setString(++index, getPosition());
        preparedStatement.setString(++index, getOccupation());
        preparedStatement.setString(++index, getPersonality());
        preparedStatement.setString(++index, getSkills());
        preparedStatement.setString(++index, getRace());
        preparedStatement.setInt(++index, getAge());
        preparedStatement.setInt(++index, getMass());
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
    public String[] getPositions() {
        return (String[]) positions.toArray();
    }

    /**
     *
     * @param positions
     */
    public void setPositions(String positions) {
        this.positions.addAll(Arrays.asList(positions.split(", ")));
    }

    /**
     *
     * @return
     */
    public String[] getOccupations() {
        return (String[]) occupations.toArray();
    }

    /**
     *
     * @param occupations
     */
    public void setOccupations(String occupations) {
        this.occupations.addAll(Arrays.asList(occupations.split(", ")));
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
}
